#include <stdio.h>

int main(void) {
	char szBuffer[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	// szBuffer2ó�� '\0'�� �����ص� �������
	// �ʱ갪�� ��õ��� ���� �迭 ��Ҵ� ��� 0���� �ʱ�ȭ�Ǳ� ����
	char szBuffer2[6] = { 'H', 'e', 'l', 'l', 'o'};
	char szData[8] = { "Hello" };
	char* pszBuffer = "Hello";

	puts(szBuffer);
	puts(szData);
	puts(pszBuffer);
	return 0;
}