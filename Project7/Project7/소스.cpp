int n, m;
int cache[100][201];
//달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때,
//m일 전까지 n미터를 기어올라갈 수 있을 확률
int climb2(int days, int climbed) {
	//기저 사례 : m일이 모두 지난 경우
	if (days == m) return climbed >= n ? 1 : 0;
	//메모이제이션
	int& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = 0.75 * climb2(days + 1, climbed + 1) + 0.25 * climb2(days + 1, climbed + 2);
}