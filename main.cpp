#include<iostream>;
using namespace std;

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

//创建链表
Node* createLinked() {
	Node* header = (Node*)malloc(sizeof(int));
	header->next = NULL;
	return header;
}

/**
 * 头插法
 * @param header 传入链表的头结点
 * @param data 这个是创建新结点的值
 */
void addHeader(Node* header,int data){
    Node* p=header;//头结点
    Node* res=header->next;//相当于一个临时变量（将最后一个节点的指针域永远保存为NULL）
    Node* node=(Node*)malloc(sizeof(Node));//为新节点开辟内存空间


    node->data=data;//将读入的数据存放到新节点的数据域中
    p->next=node;//将头指针所指向的下一个结点的地址，赋给新创建结点的next
    node->next=res;//将新创建的结点的地址赋给头指针的下一个结点
}
//尾插法
void addtail(Node* header,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=data;//将读入的数据存放到新节点的数据域中
    node->next=NULL;//新节点的下一个节点为空

    // 核心代码
    Node* p=header;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=node;
}

//查找节点
int searchNode(Node* header,int data){
    int index=0;//记录下标
    int flag=0;//旗子
    Node* p=header->next;

    while(p!=NULL){
        index++;
        if(p->data==data){
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1){
        return index;
    }else{
        return -1;
    }

}
//删除节点
void deleteNode(Node* header,int data){


//       if(header == NULL) cout<<"链表无此节点"<<endl;
//
//       Node* q=header;
//       Node* p=header->next;
//       while(p != NULL){
//           if(p->data == data ){
//               q->next=p->next;//地址前移
//               free(p);
//           }else{
//               q=q->next;
//               p=p->next;
//           }
//       }
//       if(header != NULL && header->data == data){
//           p=header;
//           header=p->next;
//           free(p);
//       }




    Node* q=header;
    Node* p=header->next;
    int flag=0;
        while(p!=NULL ){
            if(p->data == data){
                flag=1;
                q->next=p->next;//将d的下一个节点和上一个节点连接起来  地址前移
                free(p);
                break;
            }else{
                q=p;
                p=p->next;
            }
        }
    if(flag != 0){
        cout<<"删除成功"<<endl;
    }else{
        cout<<"链表无此节点"<<endl;
    }
}
//修改
void modifNode(Node* header,int data,int newdata){
    Node* p=header->next;
    int flag=0;
    if(p == NULL){
        cout<<data<<" 不在链表中"<<endl;
    }
    while(p!=NULL){
        if(p->data == data){
            p->data=newdata;
            flag=1;
        }
        p=p->next;
    }
   if(flag != 0){
        cout<<"修改成功"<<endl;
    }
}
/**
 * 输出链表
 * @param header 链表的头结点
 */
void printfLinked(Node* header){
    Node* p = header;
    while(p->next!=NULL){
        p = p->next;
        cout<< p->data<<" ";
    }
    cout<<endl;
}
int main() {
    setbuf(stdout,NULL);
    Node* header = createLinked(); //创建一个链表并且返回头结点

//头插法
    addHeader(header,3); addHeader(header,18); addHeader(header,12);
    printfLinked(header);
//尾插发
    addtail(header,1); addtail(header,2); addtail(header,3);addtail(header,3);
    printfLinked(header);
////查找
//    int index=searchNode(header,0);
//    if(index == -1) {cout<<"链表无此节点"<<endl;}else { cout<<"所输入的数据在位置"<<" =  "<<index;}
//删除
    deleteNode(header,3);
    cout<<"删除之后的新链表 :";
    printfLinked(header);

////修改
//    modifNode(header,3,4);
//    cout<<"修改之后的新链表 :";
//    printfLinked(header);
}