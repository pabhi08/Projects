#include<iostream>
using namespace std;
 
/////////////////////////////////////////////////////////////////////////////////
 
 /******struct for singly linear and singly circular*******/

/////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

/////////////////////////////////////////////////////////////////////////////////

/******struct for doubly linear and doubly circular*******/


/////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//////////////////////////////////////////////////////////////////////////////////
 
 /// Class of Singly linear linked list//////

//////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
   public :
       struct NodeS<T> *first; 
       int iCount;

         SinglyLL();
      void Display();
      int Count();

      void InsertFirst(T);
      void InsertLast(T);
      void InsertAtPos(T,int);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int);

};

template<class T>
 SinglyLL<T> ::SinglyLL()
 {
    first=NULL;
    iCount=0;
 }

template<class T>
 void SinglyLL<T> :: Display()
{
     cout<<"Elements of Singly Linear linked list are : "<<"\n";

     NodeS<T> *temp=first;

     while(temp!=NULL)
     {
        cout<<"|"<<temp->data<<" |->";
        temp=temp->next;
     }
     cout<<"NULL"<<"\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
       return iCount;
}

template<class T>
  void SinglyLL<T> :: InsertFirst(T no)
      {
             NodeS<T> *newn=new NodeS<T>;
             newn->data=no;
             newn->next=NULL;

             if(first==NULL)
             { 
                first=newn;
             }
             else
             {
                  newn->next=first;
                  first=newn;
             }
             iCount++;

      }

      template<class T>
  void SinglyLL<T> :: InsertLast(T no)
      {
           NodeS<T> *newn=new NodeS<T>;
             newn->data=no;
             newn->next=NULL;

             if(first==NULL)
             { 
                first=newn;
             }
             else
             {
                NodeS<T> *temp =first;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }   
                temp->next=newn;
             }
             iCount++;
      }

   
template<class T>
 void SinglyLL<T> :: DeleteFirst()
      {
         if(first==NULL)
         {
            return;
         }
         else if(first->next==NULL)
         {
            delete first;
            first=NULL;
         }
         else
         {
            NodeS<T> *temp=first;
            first=first->next;
            delete temp;
         }
         iCount--;
      }

      template<class T>
  void SinglyLL<T> :: DeleteLast()
      {
           if(first==NULL)
         {
            return;
         }
         else if(first->next==NULL)
         {
            delete first;
            first=NULL;
         }
         else
         {
            NodeS<T> *temp=first;
            while(temp->next->next!=NULL)
            {
               temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
         }
         iCount--;
      }

         template<class T>
 void SinglyLL<T> :: InsertAtPos(T no,int iPos)
      {
        
                int iCount=Count();

                if((iPos<1)||(iPos>iCount+1))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    InsertFirst(no);

                }
                else if (iPos==iCount+1)
                {
                    InsertLast(no);
                }
                else
                {
                    NodeS<T> *temp=first;
                    NodeS<T> *newn=new NodeS<T>;
                         newn->data=no;
                        newn->next=NULL;
                    for(int iCnt=1;iCnt<iPos-1;iCnt++)
                    {
                        temp=temp->next;
                    }
                    newn->next=temp->next;
                    temp->next=newn;

                    iCount++;
                }
      }

template<class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
   int iCount=Count();

                if((iPos<1)||(iPos>iCount))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    DeleteFirst();

                }
                else if (iPos==iCount)
                {
                    DeleteLast();
                }
                else
                {
                    NodeS<T> *temp1=first;
                    NodeS<T> *temp2=first;
                   
                    for(int iCnt=1;iCnt<iPos-1;iCnt++)
                    {
                        temp1=temp1->next;
                    }
                    temp2=temp1->next->next;
                    delete temp1->next;
                    temp1->next=temp2;
                   

                    iCount--;
                }
}

//////////////////////////////////////////////////////////////////////////////////
 
 /// Class of Singly Circular linked list//////

//////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCL
{
   public :
       struct NodeS<T> *first; 
       struct NodeS<T> *last; 
       int iCount;

      SinglyCL();
      void Display();
      int Count();

      void InsertFirst(T);
      void InsertLast(T);
      void InsertAtPos(T,int);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int);

};

template<class T>
  SinglyCL<T> ::SinglyCL()
 {
        first=NULL;
        last=NULL;
        iCount=0;
 }

template<class T>
 void SinglyCL<T> :: Display()
{
     cout<<"Elements of Singly Circular linked list are : "<<"\n";

     NodeS<T> *temp=first;

     while(temp!=NULL)
     {
        cout<<"|"<<temp->data<<" |->";
        temp=temp->next;
     }
     cout<<"NULL"<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
      return iCount;
}

template<class T>
  void SinglyCL<T> :: InsertFirst(T no)
      {
          NodeS<T> *newn=new NodeS<T>;
             newn->data=no;
             newn->next=NULL;

       if((first==NULL)&&(last==NULL))   //LL is empty
        {
          first=newn;
          last=newn;
        
        }
       else   //LL contains at least one node
       {
          newn->next=first;
          first=newn;
        
      }
       (last)->next=first; 
        iCount++;
      }

      template<class T>
  void SinglyCL<T> :: InsertLast(T no)
      {
          NodeS<T> *newn=new NodeS<T>;
             newn->data=no;
             newn->next=NULL;

       if((first==NULL)&&(last==NULL))   //LL is empty
        {
          first=newn;
          last=newn;
          (last)->next=first;
        
        }
       else   //LL contains at least one node
       {
           (last)->next=newn;
            (last)=(last)->next; 
       }
        
        (last)->next=first;
         iCount++;

      }

      template<class T>
 void SinglyCL<T> :: InsertAtPos(T no,int iPos)
      { 
           
                int iCount=Count();

                if((iPos<1)||(iPos>iCount+1))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    InsertFirst(no);

                }
                else if (iPos==iCount+1)
                {
                    InsertLast(no);
                }
                else
                {
                    NodeS<T> *temp=first;
                    NodeS<T> *newn=new NodeS<T>;
                         newn->data=no;
                        newn->next=NULL;
                    for(int iCnt=1;iCnt<iPos-1;iCnt++)
                    {
                        temp=temp->next;
                    }
                   newn->next=temp->next;
                   temp->next=newn;

                    iCount++;
                }
      }

template<class T>
 void SinglyCL<T> :: DeleteFirst()
      {
        
    if((first==NULL)&&(last==NULL))  //A
    {
         return ;
    }
    else if(first==last)   //B
    {
        free(first);     //*last is also right
        first=NULL;
        last=NULL;
    }
    else  //C
    {
         (first)=(first)->next;
        free((last)->next);
        (last)->next=first;
    }
    iCount--;
      }

      template<class T>
  void SinglyCL<T> :: DeleteLast()
      { 
           
     NodeS<T> *temp=first;
    if((first==NULL)&&(last==NULL))  //A
    {
         return ;
    }
    else if(first==last)   //B
    {
        free(first);     //last is also right
        first=NULL;
        last=NULL;
    }
    else  //C
    {
       while(temp->next!=last)
       {
        temp=temp->next;
       }
       free(last);
      last=temp;
       (last)->next=first;
    }
    iCount--;
      }

template<class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
     int iCount=Count();

                if((iPos<1)||(iPos>iCount))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    DeleteFirst();

                }
                else if (iPos==iCount)
                {
                    DeleteLast();
                }
                else
                {
                    NodeS<T> *temp=first;
                    NodeS<T> *tempX=NULL;
                      for(int iCnt=1;iCnt<iPos-1;iCnt++)
                    {
                        temp=temp->next;
                    }
                    tempX=temp->next;
                    temp->next=temp->next->next;
                    free(tempX);

                    iCount--;
                }
}
  
//////////////////////////////////////////////////////////////////////////////////
 
 ///// Class of Doubly Linear linked list//////

//////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
   public :
       struct NodeD<T> *first; 
       int iCount;

     DoublyLL();
      void Display();
      int Count();

      void InsertFirst(T);
      void InsertLast(T);
      void InsertAtPos(T,int);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int);
      
   

};

template<class T>
   DoublyLL<T> ::DoublyLL()
 {
      first=NULL;
      iCount=0;
 }

template<class T>
 void  DoublyLL<T> :: Display()
{
     cout<<"Elements of Doubly Linear linked list are : "<<"\n";

     NodeD<T> *temp=first;

     while(temp!=NULL)
     {
        cout<<"<=|"<<temp->data<<" |=>";
        temp=temp->next;
     }
     cout<<"NULL"<<"\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
   return iCount;
}

template<class T>
  void DoublyLL<T> :: InsertFirst(T no)
      {
             NodeD<T> *newn=new NodeD<T>;
             newn->data=no;
             newn->next=NULL; 
             newn->prev=NULL;
      

          if(first==NULL)   //LL is empty
           {
             first=newn;
           }

          else //LL contains at least one node in it 
           {
               (first)->prev=newn;  //#
                newn->next=first;
               first=newn;
           }
           iCount++;
      }

      template<class T>
  void DoublyLL<T> :: InsertLast(T no)
      {
         
             NodeD<T> *temp=first;
             NodeD<T> *newn=new NodeD<T>;
             newn->data=no;
             newn->next=NULL; 
             newn->prev=NULL;
      
          if(first==NULL)   //LL is empty
           {
              first=newn;
           }

         else //LL contains at least one node in it 
           {
               while(temp->next!=NULL)  //type2
                  {
                   temp=temp->next;
                   }
                   temp->next=newn;
                   newn->prev=temp;   //#
           }
           iCount++;
          
}

      template<class T>
 void  DoublyLL<T> :: InsertAtPos(T no,int iPos)
      {
          int iCount=Count();

                if((iPos<1)||(iPos>iCount+1))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    InsertFirst(no);

                }
                else if (iPos==iCount+1)
                {
                    InsertLast(no);
                }
                else
                {
                    NodeD<T> *temp=first;
                    NodeD<T> *newn=new NodeD<T>;
                     newn->data=no;
                     newn->next=NULL;
                     newn->prev=NULL;

                     for( int iCnt=1;iCnt<iPos-1;iCnt++)
                         {
                            temp=temp->next;
                         }
                        newn->next=temp->next;   //1
                        temp->next->prev=newn;   //2  #
                        temp->next=newn;          //3
                        temp->prev=temp;   
                      
                       iCount++;
                }
      }

template<class T>
 void  DoublyLL<T> :: DeleteFirst()
      {
            if(first==NULL)   //ll is empty
              {
                 return ;
              }
            else if ((first)->next==NULL)  //ll contains 1 node
              {
                 free(first);
                 first=NULL;

              }
            else   //ll contains more than 1 node
              {
                     first=(first)->next;
                    free((first)->prev);  //#
                    (first)->prev=NULL;   //#  
              }
               iCount--;
      }

      template<class T>
  void  DoublyLL<T> :: DeleteLast()
      {
          NodeD<T> *temp=first;
           if(first==NULL)   //ll is empty
              {
                 return ;
              }
            else if ((first)->next==NULL)  //ll contains 1 node
              {
                 free(first);
                 first=NULL;

              }
            else   //ll contains more than 1 node
              {
                  while(temp->next->next!=NULL)  //type 3
                    {
                        temp=temp->next;
                    }
                    free(temp->next);
                    temp->next=NULL;
              }
               iCount--;
      }

template<class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int iCount=Count();

                if((iPos<1)||(iPos>iCount))
                {
                   cout<<"invalid position\n";
                   return;
                }
                if(iPos==1)
                {
                    DeleteFirst();

                }
                else if (iPos==iCount+1)
                {
                    DeleteLast();
                }
                else
                {
                    NodeD<T> *temp=first;
                  
                     for( int iCnt=1;iCnt<iPos-1;iCnt++)
                         {
                            temp=temp->next;
                         }
                          temp->next=temp->next->next;  //1
                          free(temp->next->prev);     //2   #
                           temp->next->prev=temp;       //3   #
                      
                          iCount--;
                }
}

//////////////////////////////////////////////////////////////////////////////////
 
 ///// Class of Doubly Circular linked list//////

//////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
   public :
       struct NodeD<T> *first; 
       struct NodeD<T> *last; 
       int iCount;

        DoublyCL();
      void Display();
      int Count();

      void InsertFirst(T);
      void InsertLast(T);
      void InsertAtPos(T,int);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int);

};

template<class T>
   DoublyCL<T> ::DoublyCL()
 {
      first=NULL;
      last=NULL;
      iCount=0;
 }

template<class T>
 void  DoublyCL<T> :: Display()
{
       cout<<"Elements of Doubly Circular linked list are : "<<"\n";

     NodeD<T> *temp=first;

     while(temp!=NULL)
     {
        cout<<"<=|"<<temp->data<<" |=>";
        temp=temp->next;
     }
     cout<<"NULL"<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
   return iCount;
}

template<class T>
  void DoublyCL<T> :: InsertFirst(T no)
 {
    NodeD<T> *newn=new NodeD<T>;
    newn->data=no;
    newn->next=NULL; 
    newn->prev=NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;

 }

      template<class T>
  void DoublyCL<T> :: InsertLast(T no)
 {
    NodeD<T> *newn=new NodeD<T>;
    newn->data=no;
    newn->next=NULL; 
    newn->prev=NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }
    last -> next = first;
    first -> prev = last;
   
    iCount++;
  }

      template<class T>
 void DoublyCL<T> :: InsertAtPos(T no,int iPos)
    {
       if((iPos < 1) || (iPos > iCount+1))
         {
            cout<<"Invalid position\n";
            return;
         }
    
       if(iPos == 1)
        {
          InsertFirst(no);
        }
       else if(iPos == iCount+1)
        {
           InsertLast(no);
        }
       else
       {
           NodeD<T> *temp=first;
           NodeD<T> *newn=new NodeD<T>;
           newn->data=no;
           newn->next=NULL; 
           newn->prev=NULL;

          for(int icnt = 1; icnt < iPos -1; icnt++)
           {
              temp = temp->next;
           }

            newn->next = temp->next;
            temp->next->prev = newn;

            temp->next = newn;
            newn->prev = temp;

        iCount++;
    }
}

template<class T>
 void DoublyCL<T> :: DeleteFirst()
 {
     if(iCount == 0)         // LL is empty
       {
         return; 
       }
     else if(iCount == 1)        // LL contains one node
       {
          delete first;
          first = NULL;
          last = NULL;
       }
     else        // LL contains more than one node
     {
         first = first->next;
         delete last->next;      // delete First->prev;

         first->prev = last;
         last->next = first;
     }

      iCount--;

 }

  template<class T>
  void  DoublyCL<T> :: DeleteLast()
      {
          if(iCount == 0)         // LL is empty
            {
               return; 
            }
          else if(iCount == 1)        // LL contains one node
            {
                 delete first;
                 first = NULL;
                 last = NULL;
             }
          else        // LL contains more than one node
           {
                  last = last -> prev;
                  delete last->next;

                  first->prev = last;
                  last->next = first;
           }

      iCount--;

 }

template<class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
      if((iPos < 1) || (iPos > iCount))
         {
            cout<<"Invalid position\n";
            return;
         }
    
       if(iPos == 1)
        {
          DeleteFirst();
        }
       else if(iPos == iCount)
        {
           DeleteLast();
        }
       else
       {
           NodeD<T> *temp=first;
          
          for(int icnt = 1; icnt < iPos -1; icnt++)
           {
              temp = temp->next;
           }

             temp->next = temp->next->next;
             delete temp->next->prev;
              temp->next->prev = temp;

            iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////

///////////-----Entry Point Function-------///////////////

/////////////////////////////////////////////////////////////////////////////

int main()
{

   SinglyLL<int> obj1;
obj1.InsertFirst(51);
obj1.InsertFirst(21);
obj1.InsertFirst(11);

obj1.InsertLast(101);
obj1.InsertLast(111);

obj1.InsertAtPos(55,4);
obj1.Display();
cout<<"Number of elements are"<<obj1.Count()<<"\n";

obj1.DeleteAtPos(4);
obj1.Display();
cout<<"Number of elements are"<<obj1.Count()<<"\n";

obj1.DeleteFirst();
obj1.DeleteLast();
obj1.Display();
cout<<"Number of elements are"<<obj1.Count()<<"\n";

      return 0;
}