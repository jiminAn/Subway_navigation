#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked.h"
void append(Station **head_ref, char *new_name)
{
	Station *new_node = (Station *)malloc(sizeof(Station)); //새로운 노드 할당 

	/*-------상행 하행 시간 초기화-------*/
	for(int i = 0; i < 200; i++){
		new_node->f_time[i] = 0;
		new_node->r_time[i] = 0;
	}

	Station *last = *head_ref;
	strcpy(new_node->name, new_name);//역이름 저장 

	new_node->next = NULL;

	/*맨끝에 붙이려는 노드가 첫 노드일 경우*/
	if( *head_ref == NULL){ 
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	
	/*맨끝에 붙이려는 노드가 첫 노드가 아닐 경우*/
	while( last->next != NULL)
		last = last->next;//맨 끝노드를 가리키도록 변경

	last->next = new_node;
	new_node->prev = last;
	return;
}
void printList(Station **head_ref)
{
	/*---------------호선 정보 출력----------*/
	static int i = 1;
	if ( i < 5)
		printf("%d호선 :",i++);
	else if ( i == 5){
		printf("경전철 :");
		i++;
	}
	else if( i == 6){
		printf("동해선 :");
		i++;
	}

	/*-----해당 호선의 역이름 전체 출력--------*/
	Station *s = *head_ref;
	while( s != NULL){
		printf("(%s)", s->name);
		s = s->next;
	}
	printf("\n");
}
void d_linked(FILE *fp,Station **head_ref)
{
	char tmp_name[MAX];

	/*텍스트 파일로부터 역 이름 읽어들인 후, 읽어들인 이름으로 이중연결리스트 구성 */
	while( feof(fp) == 0){
		fscanf(fp,"%s \n",tmp_name);
		append(head_ref,tmp_name);
	}
}
void trans_infor(Station *headlist[])
{
	int i,j;
	Station *h,*t;

	/*환승역 저장*/
	for(i = 0; i < SUBWAY-1; i++){
		h = headlist[i];
		do{
			for(j = i+1; j < SUBWAY; j++){
				t = headlist[j];
				while( t != NULL){
					/*다른 호선의 역이름이 같을 때*/
					if( strcmp(h->name,t->name) == 0 ){
						     /*두 역에 각 환승 호선 정보 저장*/
                   				     if(h->trans==NULL&&t->trans==NULL){
                      					      h->trans=t;
                        				      t->trans=h;
                   				     }
					}
					t = t->next;
				}
			}
		}while((h = h->next) != NULL);
	}
}
void trans_print(Station **head_ref)
{
	Station *h = *head_ref;

	/*환승역일 경우, 환승 했을 때, 전 역, 다음 역 출력*/
	while(h != NULL){
		if( h->trans!=NULL ){
            Station *t = h->trans;
            printf("현재역: %s 환승역의 전: %s 환승역의 다음 : %s \n",h->name,t->prev->name,t->next->name);
        }
		h = h->next;
	}
}

