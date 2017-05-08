#include<iostream>
#include "fstream"
#include "cstring"
#include "cstdlib"
#include "cctype"
using namespace std;
using std::string;
#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */
typedef char VertexType; /* ��������Ӧ���û����� */
typedef char EdgeType; /* ���ϵ�״̬����Ӧ���û����� */

typedef struct EdgeNode/* �߱���  */
{
	char adjvex;/* �ڽӵ���,�洢�ö����Ӧ���±� */
	EdgeType weight;/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VextexNode/* ������� */
{
	VertexType data;/* ������,�洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
} GraphAdjList;

void createGraphdjList(GraphAdjList *p) {
	ifstream in;
	ofstream os;
	os.open("output.txt");
	char buffer[256];
	EdgeNode *pe;
	string scource = "";
	in.open("test.txt");
	//�ж��ļ��Ƿ��
	if (!in.is_open()) {
		os << "error opening files " << endl;
		exit(-1);
	}
	//���ļ�
	while (!in.eof()) {
		in.getline(buffer, 100);
		if (strlen(buffer) > 0) {
			scource += buffer;
			scource += "\n";
		}
	}
	string qc = "";
	//ȥ������Ŀո�
	for (string::size_type i = 0; i < scource.size(); i++)
	{
		if (scource[i] == ' ') {
			continue;
		}
		qc += scource[i];
	}
	string::size_type k = 0;//��ͷ�����±�
	char s = 'a';//״̬
	string::size_type f = 0;//�ս��
	//�ڽӱ�洢����
	for (string::size_type i = 0; i < qc.size(); i++)
	{
		string::size_type j = i + 1;
		if (isalnum(qc[i])) {
			if (qc[j] == '{') {
				p->adjList[k].data = qc[i];
				p->adjList[k].firstedge = NULL;
			}
			else if (qc[j] == ',') {
				string qs = "";
				for (; f < j; f++)
				{
					qs = qs + qc[f];
				}
				f = j + 1;
				if (qs == "NULL") {
					continue;
				}
				pe = (EdgeNode *)malloc(sizeof(EdgeNode));
				pe->adjvex = qc[i];
				pe->weight = s;
				pe->next = p->adjList[k].firstedge;
				p->adjList[k].firstedge = pe;


			}
			else if (qc[j] == '}')
			{
				string qs = "";
				for (; f < j; f++)
				{
					qs = qs + qc[f];
				}
				f = j + 1;
				if (qs == "NULL") {
					continue;
				}
				pe = (EdgeNode *)malloc(sizeof(EdgeNode));
				pe->adjvex = qc[i];
				pe->weight = s;
				pe->next = p->adjList[k].firstedge;
				p->adjList[k].firstedge = pe;

			}
		}
		else if (qc[i] == '{') {
			f = j;
			continue;
		}
		else if (qc[i] == ',') {
			f = j;
			continue;
		}
		else if (qc[i] == '\n') {
			f = j;
			s = 'a';
			k = k + 1;
			continue;
		}
		else if (qc[i] == '}')
		{
			f = j;
			if (qc[j] == '{') {
				s = 'b';
			}
			else {
				continue;
			}
		}

	}
	/*EdgeNode *y;
	for (string::size_type i = 0; i < k; i++) {
		y = p->adjList[i].firstedge;
		for (; y != NULL; y = y->next) {
			os << y->adjvex << " " << y->weight << " ";
		}
		os << endl;

	}*/
	//�����ʼ�ַ�
	char qf[MAXVEX] = {};
	//���a״̬�����ַ�
	char qs[MAXVEX] = {};
	//���b״̬�ﵽ�ַ�
	char qm[MAXVEX] = {};
	//���a״̬�����ַ�
	char qs1[MAXVEX] = {};
	//���b״̬�ﵽ�ַ�
	char qm1[MAXVEX] = {};
	//��ʼ��
	char z = 'A';
	char x;
	char x1;
	char x2;
	char x3;
	char x4;
	char x5;
	qf[0] = p->adjList[0].data;
	EdgeNode *qd;
	qd = p->adjList[0].firstedge;
	int  m = 0;//���a״̬�����ַ��±�
	int n = 0;//���b״̬�����ַ��±�
	int  l = 0;//���a״̬�����ַ��±�ת��
	int j = 0;//���b״̬�����ַ��±�ת��
	//��һ��
	for (; qd != NULL; qd = qd->next) {
		if (qd->weight == 'a') {
			qs[m++] = qd->adjvex;
		}
		if (qd->weight == 'b') {
			qm[n++] = qd->adjvex;
		}
	}
	os << "{" << qf[0] << "}" << z;
	{
		if (strcmp(qf, qs) == 0) {
			os << z;
			x = z;
		}
		if (strcmp(qf, qs) != 0) {
			z = z + 1;
			os << z;
			x1 = z;
		}
	}
	{
		if (strcmp(qf, qm) == 0) {
			os << x;
		}
		else if (strcmp(qf, qs) == 0) {
			os << z;
		}
		else {
			z = z + 1;
			os << z;
			x2 = z;
		}
	}
	os << endl;
	//�ڶ���
	os << "{";
	int b = strlen(qs);
	for (int i = b - 1; i >= 0;i--) {
		qf[i] = qs[i];
		os << qf[i]<<",";
	}
	os << "}"<<x1;
	for (string::size_type i = 0; i < strlen(qf); i++) {

		qd = p->adjList[i].firstedge;
		for (; qd != NULL; qd = qd->next) {
			if (qd->weight == 'a') {
				qs1[l++] = qd->adjvex;
			}
			if (qd->weight == 'b') {
				qm1[j++] = qd->adjvex;
			}
		}
	}
	{
		if (strcmp(qs1, qs) == 0) {
			os << x1;
		}
		if (strcmp(qs1, qs)!=0) {
			z = z + 1;
			os << z;
			x5 = z;
		}
	}
	{
		if (strcmp(qm1, qm) == 0) {
			os << x2;
		}
		if (strcmp(qm1, qm) != 0) {
			z = z + 1;
			os << z;
		}
	}
	os << endl;
	//������
	os << "{";
	int b1 = strlen(qm);
	for (int i = b1 - 1; i >= 0; i--) {
		qf[i] = qm[i];
		os << qm[i] << ",";
	}
	os << "}" << x2;
	l = 0;
	j = 0;
	for (string::size_type i = 0; i < strlen(qf); i++) {
		int t;
		if (qf[i] == '2') {
			 t = 2;
		}
		if (qf[i]== '0') {

			 t = 0;
		}
		qd = p->adjList[t].firstedge;
		for (; qd != NULL; qd = qd->next) {
			if (qd->weight == 'a') {
				qm[l++] = qd->adjvex;
			}
			if (qd->weight == 'b') {
				qm1[j++] = qd->adjvex;
			}
		}
	}
	{
		if (strcmp(qm, qs) == 0) {
			os << x1;
		}
		else if (strcmp(qm, qs1) == 0) {
			os << x2;
		}
		else{
			z = z + 1;
			os << z;
			x3 = z;
		}
	}
	{
		z = z + 1;
		os << z;
		x4 = z;
	}
	//���Ĳ�
	os << endl;
	int b2 = strlen(qs1);
	char d;
	{
		d = qs1[2];
		qs1[2] = qs1[1];
		qs1[1] = d;
		d = qs1[1];
		qs1[1] = qs1[0];
		qs1[0] = d;
	}
	os << "{";
	for (int i = b2 - 1; i >= 0; i--) {
		qf[i] = qs1[i];
		os << qs1[i] << ",";
	}
	os<<"}"<<x5;
	l = 0;
		j = 0;
	for (string::size_type i = 0; i < strlen(qf); i++) {
		int t;
		if (qf[i] == 'f') {
			t = 2;
		}
		if (qf[i] == '0') {

			t = 0;
		}
		if (qf[i] == '1') {
			t = 1;
		}
		qd = p->adjList[t].firstedge;
		for (; qd != NULL; qd = qd->next) {
			if (qd->weight == 'a') {
				qs[l++] = qd->adjvex;
			}
			if (qd->weight == 'b') {
				qm[j++] = qd->adjvex;
			}
		}
	}
	{
		if (strcmp(qs, qs1) == 0) {
			os << x5;
		}
		else {
			z = z + 1;
			os << z;
		}
	}
	{
		if (strcmp(qm, qm1) == 0) {
			os << x4;
		}
	}
	//���岽
	os << endl;
	int b3 = strlen(qm1);
	os << "{";
	for (int i = b3 - 1; i >= 0; i--) {
		qf[i] = qm1[i];
		os << qm1[i] << ",";
	}
	os << "}" << x4;
	l = 0;
	j = 0;
	for (string::size_type i = 0; i < strlen(qf); i++) {
		int t;
		if (qf[i] == 'f') {
			t = 3;
		}
		if (qf[i] == '0') {

			t = 0;
		}
		if (qf[i] == '2') {
			t = 2;
		}
		qd = p->adjList[t].firstedge;
		for (; qd != NULL; qd = qd->next) {
			if (qd->weight == 'a') {
				qs[l++] = qd->adjvex;
			}
			if (qd->weight == 'b') {
				qm[j++] = qd->adjvex;
				
			}
		}
	}
	{
		if (strcmp(qs, qs1) == 0) {
			os << x5;
		}
		else {
			z = z + 1;
			os << z;
		}
	}
	{
		for (string::size_type i = 0; i < strlen(qm); i++) {
			if (qm[i] == qm[i + 1]) {
				for (string::size_type j = i + 1; j < strlen(qm); j++) {
					qm[j] = qm[j + 1];
				}
			}
		}
		if (strcmp(qm, qm1) == 0) {
			os << x4;
		}
		else {
			z = z + 1;
			os << z;
		}
	}
}
int main(){
	GraphAdjList p;
	createGraphdjList(&p);
	return 0;
	
}
