#include<vector>
#include <iostream>
#include<string>

using namespace std;

const int table_size = 26;//哈希表长度

//元素状态，枚举类型
enum STATUS
{
	STATUS_NEVERUSED, STATUS_TOMBSTONE, STATUS_OCCUPIED
};

//元素结构体
typedef struct Node {
	string key;
	STATUS status;
}Node;

//插入元素
void addNode(Node* table, string item) {

	//检查是否包含
	bool isContains = false;
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED && table[index].key == item) {
			isContains = true;
		}
	}

	if (!isContains) {//不包含
		int index = item[item.size() - 1] - 'a';//映射的位置
		while (table[index].status == STATUS_OCCUPIED) {
			index = (index + 1) % table_size;
		}
		//插入
		table[index].key = item;
		table[index].status = STATUS_OCCUPIED;

	}

}

//删除元素
void eraseNode(Node* table, string item) {
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED && table[index].key == item) {
			table[index].status = STATUS_TOMBSTONE;
			return;
		}
	}
}

//主函数
int main(int argc, char* argv[]) {

	//处理输入
	string item;
	vector<string> result;
	while (cin >> item) {
		result.push_back(item);
	}

	//创建哈希表
	Node table[table_size];
	//初始化
	for (int index = 0; index < table_size; index++) {
		table[index].status=STATUS_NEVERUSED;
	}

	int size = result.size();
	for (int index = 0; index < size; index++) {
		char option = result.at(index)[0];
		string node = result.at(index).substr(1);//去掉第一个字符
		if (option == 'D') {//删除操作
			eraseNode(table, node);
		}
		else//插入操作
		{
			addNode(table, node);
		}
	}

	//打印结果
	for (int index = 0; index < table_size; index++) {
		if (table[index].status == STATUS_OCCUPIED) {
			cout << table[index].key << " ";
		}
	}

}

