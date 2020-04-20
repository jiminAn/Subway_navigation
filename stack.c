#include <stdio.h>
#include <stdlib.h>
#include "linked.h"   

void init_stack(Stack* s){
    s->top = -1;//top을 -1로 초기화
}

int isempty(Stack* s){
	return(s->top==-1);//top이 -1 이면 빈스택
}

int isfull(Stack* s){
	return(s->top==MAX-1);//스택의 최대크기보다 1 작으면 꽉찬 스택
}
void push(Station* t,Stack* s){
	if(isfull(s)){//스택에 여유공간이 없으면
		fprintf(stderr,"Error, stack is full!\n");
		return ;//에러 메세지 출력
	}
	else{//여유 공간이 있으면
		s->element[++(s->top)]=t;//삽입
		return ;
	}

}
Station* pop(Stack* s){
	if(isempty(s)){//빈스택이면
		fprintf(stderr,"Error, stack is empty!\n");
		return NULL;//에러 메세지 출력
	}   
	else{//내용이 있으면
		return s->element[(s->top)--];//내용 꺼내기
	}
}
Station* peek(Stack* s){
	if(isempty(s)){//빈 스택이면
		fprintf(stderr,"Error, stack is empty!\n");
		return NULL;//에러 메세지 출력
	}   
	else{//내용이 있으면
		return s->element[s->top];//꺼내지 않고 확인만 하기
	}
}

void print_stack(Stack* s,char *destination){
	int i;
	char tmp[50];
	printf("경로를 출력합니다 \n");

	strcpy(tmp, s->element[0]->name);//tmp에 출발역 복사
	printf("(출발역) %-6s -> ", s->element[0]->name);//출발역 출력

	/*경로: 환승x(출발역,도착역) 환승o(출발역,환승역,도착역) 으로 출력*/
	for(i = 1; i <= s->top; i++){
		if( strcmp(tmp,s->element[i]->name) != 0 ){
			if( strcmp(s->element[i]->name,destination) != 0 )
				printf("(환승역) %-6s ->", s->element[i]->name);
			else
				printf("(도착역) : %-6s", s->element[i]->name);
		}		
		strcpy(tmp, s->element[i]->name);
	}
	printf("\n");
}
