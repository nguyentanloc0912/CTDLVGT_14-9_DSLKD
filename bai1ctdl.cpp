#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct SV{
	int mssv;
	char ten[20];
};
struct node{
	SV info;
	node* link;
};
typedef struct node NODE;
void input(SV &sv){
	fflush(stdin);
	printf("nhap ma so sinh vien : ");
	scanf("%d", &sv.mssv);
	printf("nhap ten sinh vien : ");
	fflush(stdin);
	gets(sv.ten);
}
struct list{
	NODE *head;
	NODE *tail;
};
typedef struct list LIST;
void taods(LIST &l) {
	l.head=l.tail=NULL;
}
NODE *Taonode(SV sv){
	NODE *p = new NODE;
	if(p==NULL){
		printf("khong du bo nho : ");
		exit(1);
	}
	p->info = sv;
	p->link = NULL; 
	return p;
}
void themvaodau(LIST &l, NODE *p){
	if(l.tail == NULL) {
		l.head=l.tail=p;
	}else{
		p->link = l.head;
		l.head = p ;
	}
}
void themvaocuoidanhsach(LIST &l, NODE *p){
	if(l.tail == NULL) {
		l.head=l.tail=p;
	}else{
		l.tail->link = p;
		l.tail = p;
	}
}
void output(SV x){
	printf("%10d | %10s\n", x.mssv, x.ten);
}
void indslk(LIST l){
	printf("%10s | %10s\n", "MSSV", "TEN");
	for(NODE *k = l.head;k!=NULL;k=k->link){
		output(k->info);
	}
}
void xoadauds(LIST &l){
	NODE *p = l.head;
	if(l.head==NULL){
		printf("danh sach rong !");
		exit(1);
	}else{
		l.head = p->link;
		delete p;
	}
}
void xoacuoids(LIST &l){
	NODE *p = l.head;
	NODE *r = new NODE;
	while(p!=l.tail){
		r = p;
		p = p->link;
	}
	l.tail = r;
	r->link = NULL;
	delete p;
	
}
void timSV(LIST l) {
	int k;
	printf("Nhap ma so sinh vien can tim : ");
	scanf("%d", &k);
	for(NODE *p = l.head;p!=NULL;p=p->link){
		if(p->info.mssv==k){
			printf("%10s | %10s\n", "MSSV", "TEN");
			output(p->info);
			exit(1);
		}
	}
	printf("Khong tim thay sinh vien co mssv nhu vay ");
}
void sapxep(LIST l) {
	for(NODE* i=l.head;i!=l.tail;i=i->link){
		for(NODE *j = i->link;j!=NULL;j=j->link){
			if(i->info.mssv>j->info.mssv){
				SV temp = j->info;
				j->info = i->info;
				i->info = temp;
			}
		}
	}
}
int main() {
	SV sv;
	int n;
	LIST l;
	taods(l);
	printf("nhap so luong sinh vien : ");
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		input(sv);
		NODE *p = Taonode(sv);
		themvaocuoidanhsach(l, p);
	}
	//timSV(l);
	sapxep(l);
	//xoadauds(l);
	//xoacuoids(l);				
	indslk(l);
}
