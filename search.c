#include <stdio.h>
#include <string.h>
#include "linked.h"

Stack path[100];//경로를 저장할 스택 배열 
Stack last;//한번 가봤는데 도착할수 없는 경로 저장
int idx=0;//path의 인덱스

Stack search_one(Station* head[],char* start,char* destination,int currtime){
	Station* tmp,*st,*dt;
	st = dt = NULL;//출발역 도착역 초기화

	/*------전역변수 초기화-----*/	
	for(int i=0;i<100;i++)
		init_stack(&path[i]);
	init_stack(&last);
	for(int i=0;!isempty(&path[i]);i++){
		while(!isempty(&path[i]))
			pop(&path[i]);
	}
	while(!isempty(&last))
		pop(&last);
	idx=0;


	/*--------출발역 검색------------*/
	for(int i=0;i<6;i++){
		tmp=head[i];
		while(tmp!=NULL){
			if(strcmp(tmp->name,start)==0){
				st=tmp;
				break;
			}
			else
				tmp=tmp->next;
		}
		if(st!=NULL){//출발역이 두개 이상 검색될수 있는 경우 앞노선으로 검색	
			break;
		}
	}
	/*------도착역 검색-------------*/
	for(int i=0;i<6;i++){
		tmp=head[i];
		while(tmp!=NULL){
			if(strcmp(tmp->name,destination)==0){
				dt=tmp;
				break;
			}
			else
				tmp=tmp->next;
		}
		if(dt!=NULL)//도착역이 두개 이상 검색될 수 있는 경우 뒷노선으로 검색
			break;
	}
	onelinesearch(head,st,dt);//경로 검색
	
	return time_count(path,currtime);//최단시간 경로 반환
	
}	

void onelinesearch(Station* head[],Station* start,Station* destination){
	
	Station* tmp=start;//출발역
	
	push(start,&path[idx]);//출발역을 경로에 넣기

	/*다음역 검색*/
	do{	
		if(tmp==destination){//도착역을 찾은경우
			path[idx+1]=path[idx];//이전까지의 경로를 복사
			push(tmp,&path[idx++]);//도착역을 경로에 넣기

			/*복사된 경로에서의 작업*/
			while(!isempty(&last)){
				if(peek(&path[idx])==pop(&last))//이번역을 지나친것으로 처리
					break;
			}
			pop(&path[idx]);//경로를 못찾았을 경우이므로 출발역을 빼주기
			return ;
		}
		else if(tmp->trans!=NULL){//환승역인경우
			if(!errorcontrol(tmp,path[idx])){//경로상에서 환승하지 않았던 경우
				push(tmp,&path[idx]);//어디까지 가서 환승하는지 기록
				onelinesearch(head,tmp->trans,destination);//환승역을 출발역으로 하는 재귀함수 호출
				pop(&path[idx]);//환승하지 않은것으로 처리
			}
			else if(path[idx].top==0){//환승역이 출발역일 경우
				push(tmp,&path[idx]);//출발역 기록
				onelinesearch(head,tmp->trans,destination);//환승
				pop(&path[idx]);//경로를 못찾은 경우 기록삭제
			}
		
		}
		
		tmp=tmp->next;//경로를 못찾은 경우 다음역으로 이동
		if(errorcontrol(tmp,last))//이미 들어가본 역인 경우
			break;//종료
	}while(tmp!=NULL&&!errorcontrol(tmp,path[idx]));//경로상에 들어가지 않은 역만 들어가기, 노선의 끝까지 반복

	/*이전역검색*/
	tmp=start;//출발역으로 초기화
	do{
		
		if(tmp==destination){//도착역을 찾은경우
			path[idx+1]=path[idx];//이전경로복사
			push(tmp,&path[idx++]);//도착역기록
			/*복사한 경로에서의 작업*/
			while(!isempty(&last)){//도착할 수 없는 경로 수정
				if(peek(&path[idx])==pop(&last))
					break;
			}
			pop(&path[idx]);//환승하지 않은것으로 처리
			return ;
		}
		else if(tmp->trans!=NULL){//환승역인경우
			if(!errorcontrol(tmp,path[idx])){//경로상에서 환승한적이 없는 경우
				push(tmp,&path[idx]);//기록
				onelinesearch(head,tmp->trans,destination);//환승
				pop(&path[idx]);//도착하지 못했을경우 환승하지 않은것으로 기록
			}
		
		}	
		tmp=tmp->prev;//이전역으로 이동
		if(errorcontrol(tmp,last))//도착할 수 없는 경로일경우 멈춤
			break;
	}while(tmp!=NULL&&!errorcontrol(tmp,path[idx]));//경로상 안가본 역만 검색, 노선의 끝까지 반복
	push(pop(&path[idx]),&last);//못찾았을경우 출발역 삭제
	return ;
}

int errorcontrol(Station* s,Stack t){
	
	for(int i=0;i<=t.top;i++){
		if(s==t.element[i])//현재 역이 도착할 수 없는 경로인경우
			return 1;	
		
	}
	return 0;//아닌 경우
}
	 
