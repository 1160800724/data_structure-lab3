#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> s;
void DFSdigui(int a[10][10],int visit[10],char word[10],int i)
{
    int j;
    cout<<word[i]<<" ";
    visit[i]=1;
    for(j=0;j<10;j++)
    {
        if((a[i][j]==1)&&(visit[j]==0))
            DFSdigui(a,visit,word,j);
    }
}
void DFSfei(int a[10][10],int visit[10],char word[10],stack<int> s,int i)
{
    int j;
    cout<<word[i]<<" ";
    visit[i]=1;
    s.push(i);
    s.push(i);
    do{
        for(j=0;j<10;j++){
            if((a[i][j]==1)&&(visit[j]==0)){
                cout<<word[j]<<" ";
                visit[j]=1;
                i=j;
                s.push(i);
                j=-1;
            }
        }
        i=s.top();
        s.pop();
    }while(!s.empty());
}
void BFS(int a[10][10],int visit[10],char word[10],int k){
    int i,j;
    queue<int> q;
    cout<<word[k]<<" ";
    visit[k]=1;
    q.push(k);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(j=0;j<10;j++){
            if((a[i][j]==1)&&(visit[j]==0)){
                cout<<word[j]<<" ";
                visit[j]=1;
                q.push(j);
            }
        }
    }
}
void menu(){
    cout<<"����������ѡ��:"<<endl;
    cout<<"1.�õݹ�������������ͼ"<<endl;
    cout<<"2.�÷ǵݹ�������������ͼ"<<endl;
    cout<<"3.���ȹ���������ͼ"<<endl;
    cout<<"0.�˳�����"<<endl;
}
int main()
{
    int visit[10]={0,0,0,0,0,0,0,0,0,0}, b;
    char word[10]={'a','b','c','d','e','f','g','h','i','j'};
    int a[10][10]={{0,0,0,0,0,0,0,1,0,1},{0,0,0,1,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0},{0,1,1,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,0,0,0},{0,0,0,0,1,0,1,0,1,0}
    ,{0,0,0,0,0,1,0,0,0,0},{1,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,1,0,1,0,0},{1,0,0,0,0,0,0,0,0,0}};
    while(1){
    menu();
    cin>>b;
    if(b==0) break;
    switch(b)
    {
    case 1:
        cout<<"�ݹ������������Ϊ��"<<endl;
       DFSdigui(a,visit,word,0);
       cout<<endl;
       for(int i=0;i<10;i++){
        visit[i]=0;
       }
       break;
    case 2:
        cout<<"�ǵݹ������������Ϊ��"<<endl;
        DFSfei(a,visit,word,s,0);
        cout<<endl;
        for(int i=0;i<10;i++){
        visit[i]=0;
       }
        break;
    case 3:
        cout<<"�ȹ��������Ϊ��"<<endl;
        BFS(a,visit,word,0);
        cout<<endl;
        for(int i=0;i<10;i++){
        visit[i]=0;
       }
        break;
    }
    }
    return 0;
}
