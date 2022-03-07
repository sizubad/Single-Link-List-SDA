//single linked list implementasi insertion dan delete
//Siti Zubaidah
//G1A021002
//Informatika B 21

#include<iostream>
using namespace std;

template<class T>
struct node //membuat node
{
	T data;//bagian data
	node *link;//bagian link
};

template<class T>
class SingleLinkedList
{
	node<T> *start,*temp,*ptr,*prev;
	
	public:
		SingleLinkedList()//constructor
		{
			start=NULL;
		}
		
		void insbeg(T ele)//fungsi insertion di awal
		{
			temp=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
				start=temp;
			else
			{
				temp->link=start;
				start=temp;
			}
		}
		
		void insend(T ele)//fungsi insertion di akhir
		{
			temp=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
				start=temp;
			else 
			{
				ptr=start;
				while(ptr->link!=NULL)
				ptr=ptr->link;
				ptr->link=temp;
			}
		}
		
		void inspos(T ele,T pos)//fungsi insertion before/after
		{
			temp=new node<T>;ptr=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
			{
				start=temp;
				cout<<"Node ditambahkan ke dalam list"<<endl;
			}
			else if(start->link==NULL)
			{
				if(pos==1)
				{
					temp->link=start;
					start=temp;
					cout<<"Node ditambahkan kedalam list"<<endl;
				}
				else if(pos==2)
				{
					start->link=temp;
					cout<<"Node ditambahkan kedalam list"<<endl;
				}
				else
					cout<<"Pilihan salah"<<endl;
			}
			else
			{
				int i;
				ptr=start;
				if(pos==1)
				{
					temp->link=start;
					start=temp;
					cout<<"Node ditambahkan kedalam list"<<endl;
				}
				else
				{
					for(i=1;i<pos-1 && ptr->link!=NULL;i++)
						ptr=ptr->link;
					if(i==pos-1)
					{
						temp->link=ptr->link;
						ptr->link=temp;
						cout<<"Node ditambahkan ke dalam list"<<endl;
					}
					else
						cout<<"Pilihan salah"<<endl;
				}
			}
		}
				
		void delbeg()//fungsi delete di awal
		{
			if(start==NULL)
				cout<<"List kosong"<<endl;
			else if(start->link==NULL)
			{
				start=NULL;
				cout<<"Node dihapus dalam list"<<endl;
			}
			else
			{
				ptr=start;
				start=start->link;
				delete ptr;
				cout<<"Node dihapus dalam list"<<endl;
			}
		}
		
		void delend()//fungsi delete di akhir
		{

			if (start==NULL)
				cout<<"List kosong"<<endl;
			else
			{
				ptr=start;
				if(start->link==NULL)
					start=NULL;
				else
				{
					while(ptr->link!=NULL)
					{
						prev=ptr;
						ptr=ptr->link;
					}
					prev->link=NULL;
				}
				delete ptr;
				cout<<"Node dihapus dalam list"<<endl;
			}
		}
		
		void delpos(T pos)//fungsi delete after
		{
			int i;
			if (start==NULL)
				cout<<"List kosong\n";
			else
			{
				ptr=start;
				if(start->link==NULL)
				{
					if(pos==1)
						start=NULL;
					else
						cout<<"Salah posisi\n";
				}
				else
				{
					if(pos==1)
						start=start->link;
					else
					{
						for(i=1;i<pos && ptr->link!=NULL;i++)
						{
							prev=ptr;
							ptr=ptr->link;
						}
						if(i<pos)
							cout<<"Salah posisi\n";
						else
							prev->link=ptr->link;
					}
				}
				delete ptr;
				cout<<"Node dihapus dalam list"<<endl;
			}
		}

		void display()//fungsi menampilkan linked list
		{
			ptr= start;
			if (ptr==NULL)
				cout<<"Linked list kosong\n";
			else{
				cout<<"Linked list adalah :"<<endl;
				while(ptr->link!=NULL)
				{
					cout<<ptr->data<<"->";
					ptr=ptr->link;
				}
				cout<<ptr->data<<endl;
			}
		}
		
};

int main()//driver code
{
	SingleLinkedList<int> s;//linkend list class object
	int ch, e, p, flag=0;
	cout<<"Linked List"<<endl;
	do{
		cout<<"\nMemilih pilihan unruk operasi dalam linked list\n1.Insertion di awal\n2.Insertion di akhir\n3.Insertion di posisi\n4.Deletion di awal\n5.Deletion di akhir\n6.Deletion di posisi\n7.Menampilkan linked list\n8.Keluar\n"<<endl;//display menu
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Masukkan nilai node"<<endl;
				cin>>e;
				s.insbeg(e);
				cout<<"Node ditambahkan kedalam list"<<endl;
				break;
			case 2:cout<<"Masukkan nilai node"<<endl;
				cin>>e;
				s.insend(e);
				cout<<"Node ditambahkan ke dalam list"<<endl;
				break; 
			case 3:cout<<"Masukkan nilai node dan posisi"<<endl;
				cin>>e>>p;
				s.inspos(e,p);
				break;
			case 4:s.delbeg();
				break;
			case 5:s.delend();
				break;
			case 6:cout<<"Masukkan posisi"<<endl;
				cin>>p;
				s.delpos(p);
				break;
			case 7:s.display();
				break;
			case 8:flag=1;
				cout<<"Mengakhiri code\n";
				break;
			default:flag=1;
				cout<<"Pilihan salah. pilih pilihan yang benar dari menu yang diberikan."<<endl;
				break;
		}
		if (flag)
			break;
	}while(ch<9);
	return 0;
}