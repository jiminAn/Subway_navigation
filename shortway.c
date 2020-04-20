#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "linked.h"

Station *tmp_ss[100];//경로를 임시저장하는 배열

Stack time_count(Stack path[], int cur_time)
{
	
	int time;//출발시간
	int sum[100];//걸리는시간
	for(int i = 0; i < 100; i++)//걸리는 시간을 0으로 초기화
		sum[i] = 0;
	
	Stack tmp;//최단시간의 경로를 저장할 스택
	int mv,lmt;//mv : 승차부터 하차까지 걸리는 시간, lmt : 경로안의 역들의 갯수
	int i,j;//i : 경로번호, j : 임시저장 어레이의 인덱스
	int sh=-1;//최단시간을 임시저장하는 변수 초기화
	init_stack(&tmp);//스택초기화
	
	/*--스택에 저장된 경로들을 모두 비교-----------*/
	for(i = 0; !isempty(&path[i]); i++){
		time = cur_time;//출발시간은 현재시간으로 초기화
		lmt=path[i].top;//역들의 갯수 초기화
		for(j = lmt; j >= 0; j--){
			tmp_ss[j] = pop(&path[i]);//스택의 값들을 배열에 복사
		}
		j = 0;//인덱스를 처음으로 초기화
		do{     
			sum[i] += time_sum(time,tmp_ss[j],tmp_ss[j+1])-time;//출발시간부터 승차시간까지의 시간
			mv= tmp_ss[j+1]->f_time[0] - tmp_ss[j]->f_time[0];//승차시간부터 하차시간까지의 시간
			mv= (mv >= 0) ? mv : (-1)*mv;//절댓값으로 저장
			sum[i] += mv;	
			time += sum[i];//출발시간을 현재시각에 하차까지 걸린시간을 더한 값으로 초기화
			j+=2;
			if( sum[i] < -1)
				break;
		}while( j<=lmt );//역의 갯수만큼 반복
		if( sum[i] < -1)
			continue;
		
		if(time_compare(sh,sum[i])==-1){//첫 경로일 경우
			sh=sum[i];//최단시간은 첫 경로의 걸린시간
			for(int i=0;i<=lmt;i++){//결과값에 첫 경로 저장
				push(tmp_ss[i],&tmp);
			}			
		}

		/*최단시간보다 현재 경로의 걸린 시간이 클경우*/
		else if(time_compare(sh,sum[i])==0){
			continue;
		}//아무것도 하지 않음

		/*최단시간보다 현재 경로의 걸린 시간이 작을 경우*/
		else{
			while(!isempty(&tmp))//결과값 초기화
				pop(&tmp);
			sh=sum[i];//최단시간 변경
			for(int i=0;i<=lmt;i++){//결과값에 현재 경로 저장
				push(tmp_ss[i],&tmp);
			}			
		}		
	}
	printf("--------%d시 %d분 이 이동하는데 총 소요될 시간입니다---------\n", sh/60, sh%60);
	printf("역을 이동하는데 소요되는 시간 : %d분  \n", mv);
	printf("--------%d시 %d분 도착 예정입니다--------------------------\n", time/60, time%60);
	return tmp;//결과값(최단경로) 반환
}
int find_direction(Station *s, Station *s_next)
{	
	Station *tmp = s;//현재 역으로 초기화
	if(strcmp(s->name,s_next->name)==0)//현재역에서 현재역의 다른 노선으로 이동하는경우
		return 2;
	while( tmp != NULL){
		if( strcmp(tmp->name, s_next->name) == 0)
			return 1; //순방향
		tmp = tmp->next;
	}
	
	tmp = s;
	while( tmp != NULL){
		if( strcmp(tmp->name, s_next->name) == 0)
		 	return 0; //역방향
		tmp = tmp->prev;
	}
	
}
int time_sum(int cur_time, Station *s, Station *s_next)
{
	int direc = find_direction(s, s_next);//방향찾기
	int i;
	if( direc == 1){//순방향인 경우
		
		for(i = 0; ; i++){
		
			if( (s->f_time[i] - cur_time) >= 0){
		
				return s->f_time[i];//현재시각에서 가장 가까운 탑승가능한 시간 반환
			}
		}
	
	}
	else if(direc==0){//역방향인 경우
		for(int i = 0; ; i++){
			if((s->r_time[i] - cur_time)>=0){
				
				return s->r_time[i];//현재시각에서 가장 가까운 탑승가능한 시간 반환
			}
		}
		
	}
	else if(direc==2){//현재역에서 현재역으로 이동일경우
		return cur_time;//환승이라 기록되어 있지만 사실상 출발역이 환승역이므로 계산하지 않음
	}
	return -1;
}

int time_compare(int sh, int c_sum)
{
	if(sh==-1)//첫 역일 경우
		return -1;	
	else if(sh<=c_sum)//최단시간이 현재 경로의 걸린 시간보다 작을 경우
		return 0;
	else //최단시간이 현재 경로의 걸린 시간보다 클 경우
		return 1;
}

