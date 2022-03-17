#include<vector>
#include <iostream>
#include<string>

using namespace std;

const int table_size = 26;//��ϣ����

//Ԫ��״̬��ö������
enum STATUS
{
	STATUS_NEVERUSED, STATUS_TOMBSTONE, STATUS_OCCUPIED
};

//Ԫ�ؽṹ��
typedef struct Node {
	string key;
	STATUS status;
}Node;

//����Ԫ��
void addNode(Node* table, string item) {

	//����Ƿ����
	bool isContains = false;
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED && table[index].key == item) {
			isContains = true;
		}
	}

	if (!isContains) {//������
		int index = item[item.size() - 1] - 'a';//ӳ���λ��
		while (table[index].status == STATUS_OCCUPIED) {
			index = (index + 1) % table_size;
		}
		//����
		table[index].key = item;
		table[index].status = STATUS_OCCUPIED;

	}

}

//ɾ��Ԫ��
void eraseNode(Node* table, string item) {
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED && table[index].key == item) {
			table[index].status = STATUS_TOMBSTONE;
			return;
		}
	}
}

//������
int main(int argc, char* argv[]) {

	//��������
	string item;
	vector<string> result;
	while (cin >> item) {
		result.push_back(item);
	}

	//������ϣ��
	Node table[table_size];
	//��ʼ��
	for (int index = 0; index < table_size; index++) {
		table[index].status=STATUS_NEVERUSED;
	}

	int size = result.size();
	for (int index = 0; index < size; index++) {
		char option = result.at(index)[0];
		string node = result.at(index).substr(1);//ȥ����һ���ַ�
		if (option == 'D') {//ɾ������
			eraseNode(table, node);
		}
		else//�������
		{
			addNode(table, node);
		}
	}

	//��ӡ���
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED) {
			cout << table[index].key << " ";
		}
	}

}

