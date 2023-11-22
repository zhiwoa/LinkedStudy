#include<iostream>;
using namespace std;

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

//��������
Node* createLinked() {
	Node* header = (Node*)malloc(sizeof(int));
	header->next = NULL;
	return header;
}

/**
 * ͷ�巨
 * @param header ���������ͷ���
 * @param data ����Ǵ����½���ֵ
 */
void addHeader(Node* header,int data){
    Node* p=header;//ͷ���
    Node* res=header->next;//�൱��һ����ʱ�����������һ���ڵ��ָ������Զ����ΪNULL��
    Node* node=(Node*)malloc(sizeof(Node));//Ϊ�½ڵ㿪���ڴ�ռ�


    node->data=data;//����������ݴ�ŵ��½ڵ����������
    p->next=node;//��ͷָ����ָ�����һ�����ĵ�ַ�������´�������next
    node->next=res;//���´����Ľ��ĵ�ַ����ͷָ�����һ�����
}
//β�巨
void addtail(Node* header,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=data;//����������ݴ�ŵ��½ڵ����������
    node->next=NULL;//�½ڵ����һ���ڵ�Ϊ��

    // ���Ĵ���
    Node* p=header;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=node;
}

//���ҽڵ�
int searchNode(Node* header,int data){
    int index=0;//��¼�±�
    int flag=0;//����
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
//ɾ���ڵ�
void deleteNode(Node* header,int data){


//       if(header == NULL) cout<<"�����޴˽ڵ�"<<endl;
//
//       Node* q=header;
//       Node* p=header->next;
//       while(p != NULL){
//           if(p->data == data ){
//               q->next=p->next;//��ַǰ��
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
                q->next=p->next;//��d����һ���ڵ����һ���ڵ���������  ��ַǰ��
                free(p);
                break;
            }else{
                q=p;
                p=p->next;
            }
        }
    if(flag != 0){
        cout<<"ɾ���ɹ�"<<endl;
    }else{
        cout<<"�����޴˽ڵ�"<<endl;
    }
}
//�޸�
void modifNode(Node* header,int data,int newdata){
    Node* p=header->next;
    int flag=0;
    if(p == NULL){
        cout<<data<<" ����������"<<endl;
    }
    while(p!=NULL){
        if(p->data == data){
            p->data=newdata;
            flag=1;
        }
        p=p->next;
    }
   if(flag != 0){
        cout<<"�޸ĳɹ�"<<endl;
    }
}
/**
 * �������
 * @param header �����ͷ���
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
    Node* header = createLinked(); //����һ�������ҷ���ͷ���

//ͷ�巨
    addHeader(header,3); addHeader(header,18); addHeader(header,12);
    printfLinked(header);
//β�巢
    addtail(header,1); addtail(header,2); addtail(header,3);addtail(header,3);
    printfLinked(header);
////����
//    int index=searchNode(header,0);
//    if(index == -1) {cout<<"�����޴˽ڵ�"<<endl;}else { cout<<"�������������λ��"<<" =  "<<index;}
//ɾ��
    deleteNode(header,3);
    cout<<"ɾ��֮��������� :";
    printfLinked(header);

////�޸�
//    modifNode(header,3,4);
//    cout<<"�޸�֮��������� :";
//    printfLinked(header);
}