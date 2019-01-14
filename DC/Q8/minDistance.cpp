#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <utility>
#include <cstdlib>
#include<cstdio>
#define INF 10000000000.0

using namespace std;

typedef pair<double, double> Pair;

bool cmpx(const Pair &a, const Pair &b) {
	if (a.first < b.first)
		return true;
	else return false;
}

bool cmpy(const Pair &a, const Pair &b) {
	if (a.second < b.second)
		return true;
	else return false;
}

double cal_distance(Pair a, Pair b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double stripDistance(vector<Pair> p,double d) {
	double tmp = d, tmp1 = 0.0;
	sort(p.begin(), p.end(), cmpy);
	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size() && (p[j].second - p[i].second < tmp); j++) {
			tmp1 = cal_distance(p[i],p[j]);
			if (tmp1 < tmp)
				tmp = tmp1;
		}
	}
	return tmp;
}

double closestPair(vector<Pair> p) {
	
	double d = 0.0, d1 = 0.0, d2 = 0.0, d3 = 0.0, xMidPos = 0;
	
	if (1 == p.size()) {
		d = INF;
		return d;
	}
	else if (2 == p.size()) {
		d = cal_distance(p[0], p[1]);
		return d;
	}

	vector<Pair> p1, p2, stripPair;
	for (int i = 0; i < (int)(p.size() / 2); i++) {
		p1.push_back(p[i]);
	}
	for (int i = (int)(p.size() / 2); i < p.size(); i++) {
		p2.push_back(p[i]);
	}
	d1 = closestPair(p1);
	d2 = closestPair(p2);
	d = min(d1, d2);

	xMidPos = (p[p.size()/2-1].first + p[p.size()/2].first) / 2;
	for (int i = 0; i < p.size(); i++) {
		if ((p[i].first >= (xMidPos - d)) && p[i].first <= (xMidPos + d)) {
			stripPair.push_back(p[i]);
		}
	}
	d3 = stripDistance(stripPair, d);
	return d3;
}

int main() {
	int n = 0;
	double x, y, res;
	while (scanf("%d", &n) != EOF) {
		vector<Pair> p;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			p.push_back(Pair(x, y));
		}
		sort(p.begin(), p.end(), cmpx);
		res = closestPair(p);
		printf("%.2lf\n", res);
	}
	return 0;
}