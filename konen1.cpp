/********************************************
名前：Horner.c
機能：多項式計算
入力：
出力：
作者：
制作日：2019/04/09
特記事項：dp使用
********************************************/
/*
#include <stdio.h>

#define DIM 4 //多項式の最大次数

double Horner(int, double[]);

int main()
{
	double a[DIM + 1] = {2,3,4,5,6};
	for (int x = 1; x <= 5; x++) { //多項式f(x)でのx=1からx = 5までの値を求める
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
名前：Stack.c
機能：計算機
入力：
出力：
作者：
制作日：2019/04/09
特記事項：逆ポーランド記法で記述
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100  //スタックの大きさ

long stack[STACK_SIZE]; //スタック
int pointer;            //次にスタックに積まれるデータの位置

void init();     //スタック初期化
void push(long); //スタックに要素を積む
long pop();      //スタックから要素を取り出す

int main() {
	int c;
	long x, a, b;

	init();
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			ungetc(c, stdin); //入力ストリームに文字(数字)を戻す
			scanf("%ld", &x); //改めてその数字をxに入力させる
			push(x);
		}
		else {
			switch (c) {
				//すべての四則演算において、一番上の数をスタックに降ろしてbに代入
				//次の数をスタックから降ろしてaに代入
			case '+':
				//スタックからb,aの順で降ろしa+bをスタックに積む(以下同様)
				b = pop(); a = pop(); push(a + b); break;
			case '-':
				b = pop(); a = pop(); push(a - b); break;
			case '*':
				b = pop(); a = pop(); push(a * b); break;
			case '/':
				b = pop(); a = pop(); push(a / b); break;
			case '\n':
				printf("答えは%ldです.\n", pop());  init(); break;
			case ' ':
			case '\t':
				break;
			default:
				printf("不正な文字がありました. もう一度入力してください\n");
				while ((c = getchar()) != EOF && c != '\n') break;
			}
		}
	}
}

void init() { pointer = 0; };

void push(long x) {
	if (pointer == STACK_SIZE) { //スタックが満杯の場合
		printf("Stack overflow\n");
	}
	else {
		stack[pointer++] = x; //スタックにxの値を積み、ポインタを更新
	}
}

long pop() {
	if (pointer == 0) { //スタックが空の場合
		printf("Stack underflow\n");
		return 0;
	}
	else {
		return stack[--pointer]; //スタックの一番上の数を返し、ポインタを更新
	}
}
*/

/********************************************
名前：Queue.c
機能：キューの実験
入力：
出力：
作者：
制作日：2019/04/09
特記事項：なし
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 8                   //キューの長さの上限
#define next(x) ((x+1)%(QSIZE+1)) //xの次の位置を求めるマクロ

int queue[QSIZE + 1]; //リングバッファでキューの最大長をQSIZEとするにはQSIZE+1の配列が必要
int head = 0; //キューの先頭となるデータの位置
int tail = 0; //キューの末尾で次のデータが追加される位置

int enqueue(int);     //キューの末尾にデータを追加する関数
int dequeue();        //キューの先頭からデータを削除する関数
void viewqueue(void); //キューの内容を表示する関数

int main() {
	int n;
	char c;

	while (1) {
		printf("コマンドを入力(i:追加 o:削除 q終了): ");
		scanf("%c", &c);
		switch (c){
		case 'i': //データの追加する
			printf("データを入力: ");
			scanf("%d", &n);
			if (enqueue(n)) { printf("待ち行列は満杯です\n"); };
			break;
		case 'o': //データを削除
			if (dequeue()) { printf("待ち行列は空です\n"); };
			break;
		case 'q': //プログラムの終了
			printf("終了します");
			return 0;
		}
		c = getchar(); //改行コードを読み飛ばすため
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
	printf("先頭 ");
	for (int i = head; i != tail; i = next(i)) {
		printf("%d ", queue[i]);
	}
	printf("末尾\n");
	printf("head = %d, tail = %d\n", head, tail);
}
*/

/********************************************
名前：Sort.c
機能：選択、挿入、バブル、クイック
入力：
出力：
作者：
制作日：2019/04/09
特記事項：
********************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 //データ数

void generateData(int data[]);       //データを生成する関数

void selectionSort(int data[]);      //選択法
void insertionSort(int data[]);      //挿入法
void bubbleSort(int data[]);           //バブルソート
void quickSort(int data[], int left, int right); //クイックソート
int partition(int data[], int left, int right);

void viewData(int data[]);           //配列dataの内容を表示
void swap(int data[], int i, int j); //data[i]とdata[j]の内容を交換する関数


int main() {
	int data[N];

	generateData(data);
	//printf("selectionSort 使用前:\n");
	//viewData(data); //ソート前のデータを表示
	//printf("selectionSort 使用後:\n");
	selectionSort(data); //選択法の実行
	//viewData(data); //ソート後のデータを表示

	generateData(data);
	data[0] = -10 * N;
	//printf("\nInsertionSort 使用前:\n");
	//viewData(data); //ソート前のデータを表示
	//printf("InsertionSort 使用後:\n");
	insertionSort(data); //選択法の実行
	//viewData(data); //ソート後のデータを表示

	generateData(data);
	//printf("\nBubbleSort 使用前:\n");
	//viewData(data); //ソート前のデータを表示
	//printf("BubbleSort 使用後:\n");
	bubbleSort(data); //選択法の実行
	//viewData(data); //ソート後のデータを表示

	generateData(data);
	//printf("\nQuickSort 使用前:\n");
	//viewData(data); //ソート前のデータを表示
	//printf("QuickSort 使用後:\n");
	quickSort(data, 0, N - 1); //選択法の実行
	//viewData(data); //ソート後のデータを表示

	return 0;
}

void generateData(int data[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		data[i] = (rand() % (10 * N)) + (-5 * N - 1);
	}
}

void selectionSort(int data[]) {
	int idx; //i番目以降の最小の要素の位置を保存
	for (int i = 0; i < N - 1; i++) {
		idx = i;
		for (int j = i + 1; j < N; j++) {
			if (data[idx] > data[j]) idx = j;
		}
		swap(data, i, idx); //i番目の要素と最小の要素を入れ替える
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