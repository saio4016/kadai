/********************************************
���O�FHorner.c
�@�\�F�������v�Z
���́F
�o�́F
��ҁF
������F2019/04/09
���L�����Fdp�g�p
********************************************/
/*
#include <stdio.h>

#define DIM 4 //�������̍ő原��

double Horner(int, double[]);

int main()
{
	double a[DIM + 1] = {2,3,4,5,6};
	for (int x = 1; x <= 5; x++) { //������f(x)�ł�x=1����x = 5�܂ł̒l�����߂�
		printf("f(%d) = %lf\n", x, Horner(x, a));
	}
	return 0;
}

double Horner(int x, double a[]) {
	double fx[DIM+1];
	fx[0] = a[DIM];
	for (int i = 1; i <= DIM; i++) {
		fx[i] = fx[i - 1] * x + a[DIM - i];
	}
	return fx[DIM];
}
*/

/********************************************
���O�FStack.c
�@�\�F�v�Z�@
���́F
�o�́F
��ҁF
������F2019/04/09
���L�����F�t�|�[�����h�L�@�ŋL�q
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100  //�X�^�b�N�̑傫��

long stack[STACK_SIZE]; //�X�^�b�N
int pointer;            //���ɃX�^�b�N�ɐς܂��f�[�^�̈ʒu

void init();     //�X�^�b�N������
void push(long); //�X�^�b�N�ɗv�f��ς�
long pop();      //�X�^�b�N����v�f�����o��

int main() {
	int c;
	long x, a, b;

	init();
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			ungetc(c, stdin); //���̓X�g���[���ɕ���(����)��߂�
			scanf("%ld", &x); //���߂Ă��̐�����x�ɓ��͂�����
			push(x);
		}
		else {
			switch (c) {
				//���ׂĂ̎l�����Z�ɂ����āA��ԏ�̐����X�^�b�N�ɍ~�낵��b�ɑ��
				//���̐����X�^�b�N����~�낵��a�ɑ��
			case '+':
				//�X�^�b�N����b,a�̏��ō~�낵a+b���X�^�b�N�ɐς�(�ȉ����l)
				b = pop(); a = pop(); push(a + b); break;
			case '-':
				b = pop(); a = pop(); push(a - b); break;
			case '*':
				b = pop(); a = pop(); push(a * b); break;
			case '/':
				b = pop(); a = pop(); push(a / b); break;
			case '\n':
				printf("������%ld�ł�.\n", pop());  init(); break;
			case ' ':
			case '\t':
				break;
			default:
				printf("�s���ȕ���������܂���. ������x���͂��Ă�������\n");
				while ((c = getchar()) != EOF && c != '\n') break;
			}
		}
	}
}

void init() { pointer = 0; };

void push(long x) {
	if (pointer == STACK_SIZE) { //�X�^�b�N�����t�̏ꍇ
		printf("Stack overflow\n");
	}
	else {
		stack[pointer++] = x; //�X�^�b�N��x�̒l��ς݁A�|�C���^���X�V
	}
}

long pop() {
	if (pointer == 0) { //�X�^�b�N����̏ꍇ
		printf("Stack underflow\n");
		return 0;
	}
	else {
		return stack[--pointer]; //�X�^�b�N�̈�ԏ�̐���Ԃ��A�|�C���^���X�V
	}
}
*/

/********************************************
���O�FQueue.c
�@�\�F�L���[�̎���
���́F
�o�́F
��ҁF
������F2019/04/09
���L�����F�Ȃ�
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 8                   //�L���[�̒����̏��
#define next(x) ((x+1)%(QSIZE+1)) //x�̎��̈ʒu�����߂�}�N��

int queue[QSIZE + 1]; //�����O�o�b�t�@�ŃL���[�̍ő咷��QSIZE�Ƃ���ɂ�QSIZE+1�̔z�񂪕K�v
int head = 0; //�L���[�̐擪�ƂȂ�f�[�^�̈ʒu
int tail = 0; //�L���[�̖����Ŏ��̃f�[�^���ǉ������ʒu

int enqueue(int);     //�L���[�̖����Ƀf�[�^��ǉ�����֐�
int dequeue();        //�L���[�̐擪����f�[�^���폜����֐�
void viewqueue(void); //�L���[�̓��e��\������֐�

int main() {
	int n;
	char c;

	while (1) {
		printf("�R�}���h�����(i:�ǉ� o:�폜 q�I��): ");
		scanf("%c", &c);
		switch (c){
		case 'i': //�f�[�^�̒ǉ�����
			printf("�f�[�^�����: ");
			scanf("%d", &n);
			if (enqueue(n)) { printf("�҂��s��͖��t�ł�\n"); };
			break;
		case 'o': //�f�[�^���폜
			if (dequeue()) { printf("�҂��s��͋�ł�\n"); };
			break;
		case 'q': //�v���O�����̏I��
			printf("�I�����܂�");
			return 0;
		}
		c = getchar(); //���s�R�[�h��ǂݔ�΂�����
		viewqueue();
	}
}

int enqueue(int n) {
	if (next(tail) != head) {
		queue[tail] = n;
		tail = next(tail);
		return 0;
	}
	else return -1;
}

int dequeue() {
	if (head != tail) {
		head = next(head);
		return 0;
	}
	else return -1;
}

void viewqueue() {
	printf("�擪 ");
	for (int i = head; i != tail; i = next(i)) {
		printf("%d ", queue[i]);
	}
	printf("����\n");
	printf("head = %d, tail = %d\n", head, tail);
}
*/

/********************************************
���O�FSort.c
�@�\�F�I���A�}���A�o�u���A�N�C�b�N
���́F
�o�́F
��ҁF
������F2019/04/09
���L�����F
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 //�f�[�^��

void generateData(int data[]);       //�f�[�^�𐶐�����֐�

void selectionSort(int data[]);      //�I��@
void insertionSort(int data[]);      //�}���@
void bubbleSort(int data[]);           //�o�u���\�[�g
void quickSort(int data[], int left, int right); //�N�C�b�N�\�[�g
int partition(int data[], int left, int right);

void viewData(int data[]);           //�z��data�̓��e��\��
void swap(int data[], int i, int j); //data[i]��data[j]�̓��e����������֐�


int main() {
	int data[N];

	generateData(data);
	//printf("selectionSort �g�p�O:\n");
	//viewData(data); //�\�[�g�O�̃f�[�^��\��
	//printf("selectionSort �g�p��:\n");
	selectionSort(data); //�I��@�̎��s
	//viewData(data); //�\�[�g��̃f�[�^��\��

	generateData(data);
	data[0] = -10 * N;
	//printf("\nInsertionSort �g�p�O:\n");
	//viewData(data); //�\�[�g�O�̃f�[�^��\��
	//printf("InsertionSort �g�p��:\n");
	insertionSort(data); //�I��@�̎��s
	//viewData(data); //�\�[�g��̃f�[�^��\��

	generateData(data);
	//printf("\nBubbleSort �g�p�O:\n");
	//viewData(data); //�\�[�g�O�̃f�[�^��\��
	//printf("BubbleSort �g�p��:\n");
	bubbleSort(data); //�I��@�̎��s
	//viewData(data); //�\�[�g��̃f�[�^��\��

	generateData(data);
	//printf("\nQuickSort �g�p�O:\n");
	//viewData(data); //�\�[�g�O�̃f�[�^��\��
	//printf("QuickSort �g�p��:\n");
	quickSort(data, 0, N - 1); //�I��@�̎��s
	//viewData(data); //�\�[�g��̃f�[�^��\��

	return 0;
}

void generateData(int data[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		data[i] = (rand() % (10 * N)) + (-5 * N - 1);
	}
}

void selectionSort(int data[]) {
	int idx; //i�Ԗڈȍ~�̍ŏ��̗v�f�̈ʒu��ۑ�
	for (int i = 0; i < N - 1; i++) {
		idx = i;
		for (int j = i + 1; j < N; j++) {
			if (data[idx] > data[j]) idx = j;
		}
		swap(data, i, idx); //i�Ԗڂ̗v�f�ƍŏ��̗v�f�����ւ���
	}
}

void insertionSort(int data[]) {
	int idx;
	for (int i = 1; i < N; i++) {
		idx = i;
		while (data[idx - 1] > data[idx]) {
			swap(data, idx - 1, idx);
			idx--;
		}
	}
}

void bubbleSort(int data[]) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; j > i; j--) {
			if (data[j - 1] > data[j]) {
				swap(data, j - 1, j);
			}
		}
	}
}

void quickSort(int data[], int left, int right) {
	if (left < right) {
		int k = partition(data, left, right);
		quickSort(data, left, k);
		quickSort(data, k + 1, right);
	}
}

int partition(int data[], int left, int right) {
	int piv, i, j;
	piv = data[left];
	i = left;
	j = right + 1;
	while (1) {
		while (i < right && data[++i] < piv);
		while (data[--j] > piv);
		if (i >= j) { break; }
		swap(data, i, j);
	}
	swap(data, left, j);
	return j;
}

void viewData(int data[]) {
	for (int i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

void swap(int data[], int i, int j) {
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}
*/