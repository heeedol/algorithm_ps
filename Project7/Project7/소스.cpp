int n, m;
int cache[100][201];
//�����̰� days�� ���� climbed ���͸� ���ö� �Դٰ� �� ��,
//m�� ������ n���͸� ���ö� �� ���� Ȯ��
int climb2(int days, int climbed) {
	//���� ��� : m���� ��� ���� ���
	if (days == m) return climbed >= n ? 1 : 0;
	//�޸������̼�
	int& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = 0.75 * climb2(days + 1, climbed + 1) + 0.25 * climb2(days + 1, climbed + 2);
}