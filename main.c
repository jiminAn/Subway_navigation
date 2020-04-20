#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linked.h"
int main(void)
{
	/*현재시각을 불러오기 위해 필요한 변수 선언*/
	time_t t; 
	struct tm *lt;
	int currtime;
	

	Stack result;
	init_stack(&result);

	FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;// 5,6 순서대로 경전철,동해선
	Station *head1, *head2, *head3, *head4, *head5, *head6; //지하철 호선별 이중연결리스트 head
	Station *head[SUBWAY];//지하철 호선별 head를 저장할 배열
	head1 = head2 = head3 = head4 = head5 = head6 = NULL;

	/*----------------호선별 지하철역 읽어서 이중연결리스트에 넣고, 각 역 별 배차시간 넣기-----------*/
	fp1 = fopen("1호선.txt","r");
	d_linked(fp1,&head1);
	time_init1(&head1);
	fclose(fp1);

	fp2 = fopen("2호선.txt","r");
	d_linked(fp2, &head2);
	time_init2(&head2);
	fclose(fp2);

	fp3 = fopen("3호선.txt","r");
	d_linked(fp3, &head3);
	time_init3(&head3);
	fclose(fp3);
		
	fp4 = fopen("4호선.txt","r");
	d_linked(fp4,&head4);
	time_init4(&head4);
	fclose(fp4);
	
	fp5 = fopen("경전철.txt","r");
	d_linked(fp5,&head5);
	time_init5(&head5);
	fclose(fp5);
   	
	fp6 = fopen("동해선.txt","r");
	d_linked(fp6,&head6);
	time_init6(&head6);
	fclose(fp6);
	
	
	head[0] = head1; head[1] = head2; head[2] = head3; 
	head[3] = head4; head[4] = head5;  head[5] = head6;

        trans_infor(head);//환승역 입력
    	
 	char start[50],destination[50]; //길찾기에서 입력받을 출발역, 도착
	int option;

	do{
		t = time(NULL);
		lt = localtime(&t);
		printf("=================================================\n");
		printf("현재 시각 : %4d년%2d월%2d일%2d시%2d분 입니다 \n",lt->tm_year + 1900,lt->tm_mon +1,lt->tm_mday,lt->tm_hour,lt->tm_min);
		printf("=================================================\n");
		currtime = (lt->tm_hour*60) + (lt->tm_min); //현재시각 분으로 바꾸기
	
		printf("----------------------menu----------------------\n");
		printf("1.역 시간표 | 2.길찾기 | 3.종료 \n");
		printf("------------------------------------------------\n");
		scanf("%d", &option);
		switch(option){
			case 1://알고싶은 역 입력받은 후 해당 시각안의 열차 배차간격 출력   
				option1(head,currtime);
				break;
			case 2://출발역과 도착역을 입력받은 후 최단 시간, 최단 경로 출력	
				printf("출발역 :");scanf("%s",start); getchar();
				printf("도착역 :");scanf("%s",destination); getchar();
        			result = search_one(head,start,destination,currtime); //최단경로 찾기
				print_stack(&result,destination);//최단경로 출력 
				break;
			case 3://종료옵션 
				break;
		}
	}while( option != 3 );
	return 0;
}










