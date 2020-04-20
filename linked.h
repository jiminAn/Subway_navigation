#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define MAXSIZE 6
#define SUBWAY 6 //호선 개수 


typedef struct station{
	char name[MAX]; // 역이름
	int f_time[200];// 순방향 배차 정보 
	int r_time[200];// 역방향 배차 정보 
	struct station *next; // 다음 노드 
	struct station *prev; // 이전 노드 
 	struct station *trans; //환승 역 노드 
	
}Station;

typedef struct stack{
	Station* element[30];//역 30개 저장 가능
	int top;//위치
}Stack;

/*------------------<linked.c>-------------------*/
void append(Station **head_ref, char *new_name);//이중연결리스트 맨 끝에 새로운 노드 삽입  
void printList(Station **head_ref);//호선별 역 전체 출력 
void d_linked(FILE *fp,Station **head_ref);//파일로부터 역 읽어들여 이중연결리스트 구성 
void trans_infor(Station *headlist[]);//환승역 정보 저장 
void trans_print(Station **head_ref); //환승역 정보 저장이 잘 되었는지 확인 
/*------------------<search.c>-------------------*/
Stack search_one(Station *head[], char *start,char *destination,int currtime); //출발역, 도착역 찾기 
int errorcontrol(Station*,Stack);//도착할 수 없는 경로 관리
void onelinesearch(Station *head[],Station* start,Station* destination);//길찾기의 모든 경로 스택에 저장 
/*------------------<stack.c>-------------------*/
void init_stack(Stack*);//스택 초기화 함수
int isempty(Stack*);//빈스택인지 확인
int isfull(Stack*);//스택이 꽉 찼는지 확인
void push(Station*,Stack*);//삽입
Station* pop(Stack*);//내용 꺼내기
Station* peek(Stack*);//내용 확인하기
void print_stack(Stack*,char *);//최단경로 출력 
/*------------------<time.c>---------------------------*/
void time_init1(Station **head_ref);//1호선 배차시간 초기화 
void time_init2(Station **head_ref);//2호선 배차시간 초기화 
void time_init3(Station **head_ref);//3호선 배차시간 초기화 
void time_init4(Station **head_ref);//4호선 배차시간 초기화 
void time_init5(Station **head_ref);//경전철 배차시간 초기화 
void time_init6(Station **head_ref);//동해 배차시간 초기화 
void print_traintime(Station **head_ref);//전체 역 첫차,막차 시간표 출력 
/*------------------<shortway.c>----------------------------------------*/
Stack time_count(Stack path[], int cur_time);//최단시간의 경로를 구하는 함수
int find_direction(Station *s, Station *s_next);//방향을 찾는 함수 
int time_sum(int cur_time, Station *s, Station *s_next);//현재시각에서 가장 가까운 탑승가능한 시간 찾기
int time_compare(int sh, int c_sum);//시간 비교 함수
/*------------------<timetable.c>----------------------------------------*/
void option1(Station *head[],int currtime);//option1 역 시간표 정보 
void print_timetable(Station *s,int currtime); //option1: 해당 역 시간표 출력 
