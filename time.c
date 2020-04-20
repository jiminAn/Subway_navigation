#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked.h"


void time_init1(Station **head_ref)
{//순방향: 다대포해수욕장->노포역 || 역방향 : 노포->다대포해수욕
	int f_first_train = 304; // 순방향 첫차 새벽 5시 4분
	int f_last_train = 1391; // 순방향 막차 밤 11시 11분
	int r_first_train = 308; // 역방향 첫차 새벽 5시 8분
	int r_last_train = 1411; // 역방향 막차 밤 11시 31분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}

void time_init2(Station **head_ref)
{//순방향 양산->장산 || 역방향 장산->양산   
	int f_first_train = 311; // 순방향 첫차 새벽 5시 11분
	int f_last_train = 1387; // 순방향 막차 밤 11시 7분
	int r_first_train = 318; // 역방향 첫차 새벽 5시 18분
	int r_last_train = 1391; // 역방향 막차 밤 11시 11분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}
void time_init3(Station **head_ref)
{//순방향 대저->수영 || 역방향 수영-> 대저  
	int f_first_train = 316; // 순방향 첫차 새벽 5시 16분
	int f_last_train = 1420; // 순방향 막차 밤 11시 40분
	int r_first_train = 320; // 역방향 첫차 새벽 5시 20분
	int r_last_train = 1439; // 역방향 막차 밤 11시 59분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}
void time_init4(Station **head_ref)
{//순방향 안평->미남 || 역방향 미남->안평    
	int f_first_train = 305; // 순방향 첫차 새벽 5시 5분
	int f_last_train = 1424; // 순방향 막차 밤 11시 44분
	int r_first_train = 340; // 역방향 첫차 새벽 5시 40분
	int r_last_train = 1460;// 역방향 막차 밤 12시 20분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}
void time_init5(Station **head_ref)
{//순방향 가야대->사상  || 역방향 사상 -> 가야대   
	int f_first_train = 300; // 순방향 첫차 새벽 5시 0분
	int f_last_train = 1421; // 순방향 막차 밤 11시 41분
	int r_first_train = 300; // 역방향 첫차 새벽 5시 0분
	int r_last_train = 1421; // 역방향 막차 밤 11시 41분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}
void time_init6(Station **head_ref)
{//순방향 부전->일광 || 역방향 일광-> 부전  
	int f_first_train = 330; // 순방향 첫차 새벽 5시 30분
	int f_last_train = 1425; // 순방향 막차 밤 11시 45분
	int r_first_train = 330; // 역방향 첫차 새벽 5시 30분
	int r_last_train = 1414; // 역방향 막차 밤 11시 34분
	int tmp_train;
	Station *tmp = *head_ref;
	int i,j;
	
	for(i = 0; i < 200; i++){// 순방향 열차 시간 넣기
		tmp_train = f_first_train;
		while( tmp != NULL){
			tmp->f_time[i] = tmp_train;
			tmp_train += 2; // 배차간격 2분
			tmp = tmp->next;
		}
		tmp = *head_ref;
		f_first_train += 10; // 각 호선의 첫 역에서 열차 출발 후 다음 열차 출발까지의 열차 배차 시간
		if( f_first_train > f_last_train)
			break;
	}
	tmp = *head_ref;
	for(j = 0; j < 200; j++){// 역방향 열차 시간 넣기
		tmp_train = r_first_train;
		while( tmp->next != NULL)
			tmp = tmp->next;
		do{
			tmp->r_time[j] = tmp_train;
			tmp_train += 2;
			tmp = tmp->prev;
		}while( tmp != NULL);
		tmp = *head_ref;
		r_first_train += 10;
		if( r_first_train > r_last_train)
			break;
	}
}


void print_traintime(Station **head_ref)
{
	Station *tmp = *head_ref;
	char *first_station = tmp->name;
	char *last_station;
	int i,j;
	while(tmp->next != NULL)
		tmp = tmp->next;
	last_station = tmp->name;
	tmp = *head_ref;

	/*1호선~4호선, 경전철, 동해선 각 역의 첫차 막차 시간표 전체 출력*/
	while(tmp != NULL){
		printf("=================%s역 열차시간표==================\n",tmp->name);
		for(i = 0; tmp->f_time[i] != 0; i++)
			if( i == 0)
				printf("하행(%s행) 첫차 : %d시 %d분 \n", last_station, (tmp->f_time[i] / 60) , (tmp->f_time[i] % 60 ) );
		printf("하행(%s행) 막차: %d시 %d분 \n",last_station, (tmp->f_time[i-1] /60), (tmp->f_time[i-1] % 60) );
		for(j = 0; tmp->r_time[j] != 0; j++)
			if( j == 0)
				printf("상행(%s행) 첫차: %d시 %d분 \n",first_station, (tmp->r_time[j] / 60) , (tmp->r_time[j] % 60 ) );
		printf("상행(%s행) 막차: %d시 %d분 \n",first_station, (tmp->r_time[j-1] / 60), (tmp->r_time[j-1] % 60) );
		tmp = tmp->next;
	}
}
	
			
		
			
	


