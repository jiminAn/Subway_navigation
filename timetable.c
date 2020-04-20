#include <stdio.h>
#include <string.h>
#include "linked.h"

int station_num[2];

void option1(Station *head[],int currtime)
{
	int num;
	char station[50];
	printf("역: ");
	scanf("%s",station);

	Station *tmp;
	Station *station_infor[2] = {NULL, NULL};// 환승역일 경우를 구분하기 위한 변수 초기화  
	int j = 0;

	for(int i = 0; i < SUBWAY; i++){
		tmp = head[i];
		while(tmp !=  NULL){
			if( strcmp(tmp->name,station) == 0){ //역 찾았을 경우 역 저장, 호선 정보 저장 
				station_infor[j] = tmp;
				station_num[j++] = i+1;
				break;
			}
			tmp = tmp->next;
		}
	}
	if( station_infor[0] == NULL)//존재역이 아님 
		printf("찾으시는 역은 존재하지 않습니다 \n");
	else if( station_infor[1] == NULL) //역이 1개 존재
		print_timetable(station_infor[0],currtime);
	else{//역이 2개 존재
		printf(" %d호선 %s역과 %d호선 %s역 중 어느 호선을 선택하시겠습니까? \n",station_num[0],station,station_num[1],station);
		scanf("%d", &num);
		if( num == station_num[0] )
			print_timetable(station_infor[0],currtime);
		else if( num == station_num[1] )
			print_timetable(station_infor[1],currtime);
	}
}	
				
void print_timetable(Station *s,int currtime)
{
	int i,j,k;
	k = j = 0;

	/*현재시각의 시간 배차간격만 출력하기 위한 계산(예: 현재시각4시 50분, 4시의 배차표만 보여줌) */
	while( (s->f_time[k] / 60) < (currtime / 60) )
		k++;
	while( (s->r_time[j] / 60) < (currtime / 60) )
		j++;

	printf("=================%s역 열차시간표==================\n",s->name);
	printf("--------------------하행------------------------\n");
	do{
		printf("%d시 %d분 \n", (s->f_time[k] / 60) , (s->f_time[k] % 60 ) );
		k++;
	}while( ((s->f_time[k] / 60) == (currtime / 60)) && (s->f_time[k] != 0) );

	printf("--------------------상행------------------------\n");
	do{
		printf("%d시 %d분 \n", (s->r_time[j] / 60) , (s->r_time[j] % 60 ) );
		j++;
	}while( ((s->r_time[j] / 60) == (currtime / 60)) && (s->r_time[j] != 0) );

}

