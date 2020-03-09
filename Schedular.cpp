#include <iostream>

using namespace std;

class FCFS {
public:
     //getters
     int get_arrivalTime(){return arrivalTime;}
     int get_burstTime(){return burstTime;}
     int get_processNum(){return processNum;}
    int get_DepartureTime(){return DepartureTime;}
     FCFS *get_next (){return next;}
     FCFS *get_pre (){return pre;}
     //setters
     void set_arrivalTime(int i){arrivalTime=i;}
     void set_processNum(int i ){processNum=i;}
     void set_burstTime(int i){burstTime=i;}
    void set_DepartureTime(int i){DepartureTime=i;}
     void set_next (FCFS *i){next=i;}
     void set_pre (FCFS *i){pre=i;}
         
private:
    int processNum,arrivalTime,burstTime,DepartureTime;
    FCFS *next=nullptr,*pre=nullptr;
    };
    
class SJF{
    public:
      //getters
     int get_arrivalTime(){return arrivalTime;}
     int get_burstTime(){return burstTime;}
     int get_processNum(){return processNum;}
     int get_DepartureTime(){return DepartureTime;}
     SJF *get_next (){return next;}
     SJF *get_pre (){return pre;}
     //setters
     void set_arrivalTime(int i){arrivalTime=i;}
     void set_processNum(int i ){processNum=i;}
     void set_burstTime(int i){burstTime=i;}
    void set_DepartureTime(int i){DepartureTime=i;}
     void set_next (SJF *i){next=i;}
     void set_pre (SJF *i){pre=i;}
    
private: 
    int arrivalTime,burstTime,processNum,DepartureTime,rem;
    SJF *next=nullptr ,*pre=nullptr;
    };
    
class PRI{
    public:
      //getters
     int get_burstTime(){return burstTime;}
     int get_priority(){return priority;}
     int get_processNum(){return processNum;}
    int get_DepartureTime(){return DepartureTime;}
     PRI *get_next (){return next;}
     PRI *get_pre (){return pre;}
     //setters
     void set_processNum(int i ){processNum=i;}
    void set_priority(int i ){priority=i;}
     void set_burstTime(int i){burstTime=i;}
    void set_DepartureTime(int i){DepartureTime=i;}
     void set_next (PRI *i){next=i;}
     void set_pre (PRI *i){pre=i;}
    
private: 
    int priority,burstTime,processNum,DepartureTime;
    PRI *next=nullptr ,*pre=nullptr;
    };
    
class RR{
    public:
      //getters
     int get_burstTime(){return burstTime;}
     int get_rem(){return rem;}
     int get_processNum(){return processNum;}
    int get_DepartureTime(){return DepartureTime;}
     RR *get_next (){return next;}
     RR *get_pre (){return pre;}
     //setters
     void set_processNum(int i ){processNum=i;}
    void set_rem(int i ){rem=i;}
     void set_burstTime(int i){burstTime=i;}
    void set_DepartureTime(int i){DepartureTime=i;}
     void set_next (RR *i){next=i;}
     void set_pre (RR *i){pre=i;}
    
private: 
    int rem,burstTime,processNum,DepartureTime;
    RR *next=nullptr ,*pre=nullptr;
    };
    
FCFS *first=nullptr;
SJF *first1 =nullptr;
PRI *first2 =nullptr;
RR *first3 =nullptr;

class printBox {
    public:
    template <class T>
    printBox(T *ff){
        T *f;
        f=ff;
        
        while (f != nullptr){
            printLine(f->get_burstTime(),1);
            f=f->get_next();
            }
        f=ff;
        cout <<"\n";
        while (f != nullptr){
            printSides1(f->get_burstTime());
            f=f->get_next();
            }
        f=ff;
        cout <<"\n";
        while (f != nullptr){
            printSides2(f);
            f=f->get_next();
            }
        f=ff;
        cout <<"\n";
        while (f != nullptr){
            printSides3(f->get_burstTime());
            f=f->get_next();
            }
            cout <<"\n";
        }
    void printLine (int s,int k) {
        s*=4;
        if (k==1)cout <<" ";
        for (int i = 0 ; i<s; i++){
        cout <<"_";
        }
        if (k==1)cout <<" ";

    }
    void printSides1(int s){
    s*=4;
    cout <<"|";
    for (int i = 0 ;i<s;i++)cout <<" ";
    cout <<"|";
    }
    template <class T>
    void printSides2(T *s){
    int ss=s->get_burstTime();
        ss*=4;
        cout <<"|";
         for (int i = 0 ;i<(ss/2);i++)cout <<" ";
    cout <<s->get_processNum();
    for (int i =(ss/2)+1 ;i<ss;i++)cout <<" ";
    cout <<"|";
    }
    void printSides3(int s){
        s*=4;
        cout <<"|";
        printLine(s/4,0);
        cout <<"|";
    }
    void printBT(FCFS *ss){
        int s =ss->get_burstTime();
        s*=4;
        for (int i = 0 ;i < (s/2);i++)cout <<" ";
        cout << ss->get_burstTime();
         for (int i = (s/2)+1 ;i < s;i++)cout <<" ";
        }
    };
    
void takeItemFCFS();

SJF *getShortJopNP (SJF *f, int &time);
void SJFList (SJF *f,int isP);
void takeItemSJF(int isP) ;

void takeItemPRI();

void RRList(RR *f,int Q);
void takeItemRR();

template <class S>
void else1 (S *s, S *ptr);

template <class K>
void else2 (K *s,K *ptr);
     
int main(){//begin main
    short int type;
    cout <<"Please Select A Schedular Type From The List Below (Enter A Number ^_^) \n* (1)FCFC\n* (2)SJF\n* (3)Priority\n* (4)Round Robin\n";
    cin>>type;
    if (type == 2){
        
             takeItemSJF(0);
        
    }//If Type 2
    
    else if (type == 3){
        
             takeItemPRI();
            
            }//If type 3
    
    else if (type==1){
    
        takeItemFCFS();
        
        }
    else if (type== 4){
        
         takeItemRR();
        
        }
    else cout << "ERROR \n";
        
    }
    
 void takeItemFCFS(){
     int arrivalTime,i=1,burstTime,departureTime=0 ;
     float AWT;
     FCFS *ptr=nullptr;
     cout << "Please Enter The Arrival & Burst Time Of Each Process And - Num to Finish Inputs\n";
     cout <<"(#"<<i<<") Arrival Time: ";
     cin>>arrivalTime;
     while (arrivalTime >= 0){//while
         
            cout <<"Burst Time: ";
            cin>>burstTime;
            FCFS *s=new FCFS ();
            s->set_processNum(i);
            s->set_arrivalTime(arrivalTime);
            s->set_burstTime(burstTime);
            
            if (first==nullptr){first=s;}
            
            else{//Else # 1
                ptr=first;
                while (ptr != nullptr){
                    
                    if (ptr->get_arrivalTime() == s->get_arrivalTime()){//IF
                    else1 (s,ptr);
                    break;
                    }//End If 
                    
                    else if (ptr->get_arrivalTime() < s->get_arrivalTime() && ptr->get_next()!= nullptr)ptr=ptr->get_next();
                    
                    else if (ptr->get_arrivalTime() < s->get_arrivalTime() && ptr->get_next()== nullptr){
                        ptr->set_next(s);
                        s->set_pre(ptr);
                        break;
                    }//else
                     
                    else if (ptr->get_arrivalTime() > s->get_arrivalTime() && ptr!= first){//Else If 
                    else2(s,ptr);
                    break;
                    }//End Else if 
                    
                    else if (ptr->get_arrivalTime() > s->get_arrivalTime() && ptr == first){//Else If 
                    first=s;
                    s->set_next(ptr);
                    ptr->set_pre(s);
                    break;
                    }//if
                }//end inner while 
        
                }//end Else  #1
                i++;
            cout <<"\t**********\n";
            cout <<"(#"<<i<<") Arrival Time: ";
            cin>>arrivalTime;
            
        }//end While
        
        printBox b(first);
        ptr=first;
        departureTime=ptr->get_arrivalTime();
        
        while (ptr != nullptr){
            departureTime+=ptr->get_burstTime();
            ptr->set_DepartureTime(departureTime);
            ptr=ptr->get_next();
            }
        departureTime=0;
        ptr=first;
            
        while (ptr != nullptr){
            departureTime+=ptr->get_DepartureTime()-ptr->get_burstTime()-ptr->get_arrivalTime();
            ptr=ptr->get_next();
            }
        AWT=float (departureTime)/float (i-1);
        cout <<"\nAverage Waiting Time is :" << AWT<<endl; 
     }  

void takeItemSJF(int isP) {//if isP==1 then preemtive 
     int arrivalTime,i=1,burstTime,departureTime=0;
     float AWT;
     SJF *ptr=nullptr;
     cout << "Please Enter The Arrival & Burst Time Of Each Process And - Num to Finish Inputs\n";
     cout <<"(#"<<i<<") Arrival Time: ";
     cin>>arrivalTime;
     while (arrivalTime >= 0){
            cout <<"Burst Time: ";
            cin>>burstTime;
            SJF *s=new SJF ();
            s->set_processNum(i);
            s->set_arrivalTime(arrivalTime);
            s->set_burstTime(burstTime);
            if (first1==nullptr){first1=s;}
            else{//Else # 1
                ptr=first1;
                while (ptr != nullptr){
                    
                    if (ptr->get_arrivalTime() == s->get_arrivalTime()){//IF
                    else1(s,ptr);
                    break;
                    }//End If 
                    else if (ptr->get_arrivalTime() < s->get_arrivalTime() && ptr->get_next()!= nullptr){ptr=ptr->get_next();}
                    else if (ptr->get_arrivalTime() < s->get_arrivalTime() && ptr->get_next()== nullptr){ptr->set_next(s);
                    s->set_pre(ptr);
                    break;}
                    else if (ptr->get_arrivalTime() > s->get_arrivalTime() && ptr->get_pre() != nullptr){//Else If 
                    else2(s,ptr);
                    break;
                    }//End Else if 
                    else if (ptr->get_arrivalTime() > s->get_arrivalTime() && ptr->get_pre() == nullptr){//Else If 
                    first1=s;
                    s->set_next(ptr);
                    ptr->set_pre(s);
                    break;
                    }
                }
        
                }//end Else  #1
                i++;
            cout <<"\t**********\n";
            cout <<"(#"<<i<<") Arrival Time: ";
            cin>>arrivalTime;
            
        }//end While
        
        SJFList(first1,isP);
        ptr=first1;
        departureTime=0;
        while (ptr != nullptr){
            departureTime+=ptr->get_DepartureTime()-ptr->get_burstTime()-ptr->get_arrivalTime();
            ptr=ptr->get_next();
            }
            AWT=float (departureTime)/float (i-1);
            cout <<"\nAverage Waiting Time is :" << AWT<<endl; 
    }
     
SJF *getShortJopNP (SJF *f, int &time){
            SJF *rF=nullptr, *x=nullptr, *y=nullptr;
            int min=f->get_burstTime() ;
             rF=f;
             while (f->get_arrivalTime() <= time ){
                if ( f->get_burstTime() < min){min=f->get_burstTime();rF=f;}
                if(f->get_next()==nullptr){break;}
                f=f->get_next();
                }
            time+= rF->get_burstTime();
            rF->set_DepartureTime(time);
            f=rF;
            if (first1==rF){first1=first1->get_next();}
            else if (f->get_next()==nullptr){f=f->get_pre();f->set_next(nullptr);}
            else {
            x=f->get_pre();
            y=f->get_next();
            f=f->get_pre();
            f->set_next(y);
            f=f->get_next();
            f->set_pre(x);
            }
            return rF;
            }
            
void SJFList (SJF *f,int isP){

                int time =f->get_arrivalTime();
            SJF *rF;
            SJF *r;
            r=getShortJopNP(first1,time);
            rF=r;
            while (first1 != nullptr){
                r->set_next(getShortJopNP(first1,time));
                r=r->get_next();
                }
            
            
            printBox a(rF);
            first1=rF;
            }
    
void takeItemPRI(){
        
     int pri,i=1,burstTime,departureTime=0;
     float AWT;
     PRI *ptr=nullptr;
     cout << "Please Enter The Burst Time & Priority Of Each Process And - Num to Finish Inputs\n";
     cout <<"(#"<<i<<") Burst Time: ";
     cin>>burstTime;
     while (burstTime >= 0){
            cout <<"Priority: ";
            cin>>pri;
            PRI *s=new PRI ();
            s->set_processNum(i);
            s->set_priority(pri);
            s->set_burstTime(burstTime);
            if (first2==nullptr){first2=s;}
            else{//Else # 1
                ptr=first2;
                while (ptr != nullptr){
                    
                    if (ptr->get_priority() == s->get_priority()){//IF
                    else1(s,ptr);
                    break;
                    }//End If 
                    else if (ptr->get_priority() < s->get_priority() && ptr->get_next()!= nullptr){ptr=ptr->get_next();}
                    else if (ptr->get_priority() < s->get_priority() && ptr->get_next()== nullptr){ptr->set_next(s);
                    s->set_pre(ptr);
                    break;}
                    else if (ptr->get_priority() > s->get_priority() && ptr != first2){//Else If 
                    else2(s,ptr);
                    break;
                    }//End Else if 
                    else if (ptr->get_priority() > s->get_priority() && ptr==first2){//Else If 
                    first2=s;
                    s->set_next(ptr);
                    ptr->set_pre(s);
                    break;
                    }
                }
        
                }//end Else  #1
                i++;
            cout <<"\t**********\n";
            cout <<"(#"<<i<<") Burst Time: ";
            cin>>burstTime;
            
        }//end While
        printBox c(first2);
        ptr=first2;
        departureTime=0;
        int time =0;
        while (ptr != nullptr){
            departureTime+=(time+ptr->get_burstTime())-ptr->get_burstTime();
            time+=ptr->get_burstTime();
            ptr=ptr->get_next();
            }
            AWT=float (departureTime)/float (i-1);
            cout <<"\nAverage Waiting Time is :" << AWT<<endl; 
        
        }
        
void takeItemRR(){
            
            
     int Q,i=1,burstTime,departureTime=0;
     float AWT;
     RR *ptr=nullptr;
     cout << "Please Enter Quantum Time \n";
     cin >>Q;
     cout << "Please Enter The Burst Time Of Each Process And - Num to Finish Inputs\n";
     cout <<"(#"<<i<<") Burst Time: ";
     cin>>burstTime;
     while (burstTime >= 0){
            RR *s=new RR ();
            s->set_processNum(i);
            s->set_burstTime(burstTime);
            s->set_rem(burstTime);
            if (first3==nullptr){first3=s;}
            else{//Else # 1
                ptr=first3;
                while (ptr->get_next() != nullptr){ptr=ptr->get_next();}
                ptr->set_next(s);
                }//end Else  #1
                i++;
            cout <<"\t**********\n";
            cout <<"(#"<<i<<") Burst Time: ";
            cin>>burstTime;
            
        }//end While
        RRList(first3,Q);

            }
void RRList(RR *f,int Q){
            
            int time=0,count =0;
            RR *nFirst=nullptr;
            RR *newItem = new RR();
            RR *lastI=new RR();
            bool finished = false;
            float AWT;
            while (! finished )
                
                {
                    
            if (f->get_rem()==0 && f->get_next() != nullptr){}//Skip Element if its not the last element
            else if (f->get_rem()==0 && f->get_next() == nullptr){delete newItem;}
            else if (f->get_rem()>Q && f->get_rem() != 0){
                newItem->set_burstTime(Q);
                newItem->set_processNum(f->get_processNum());
                if (nFirst == NULL){nFirst=newItem;lastI = newItem;}
                else {lastI->set_next(newItem);lastI=lastI->get_next();}
                f->set_rem(f->get_rem()-Q);time+=Q;
                if (f->get_next() != nullptr )
                newItem = new RR();}
            else if (f->get_rem() <= Q && f->get_rem() != 0){
                time+= f->get_rem();f->set_DepartureTime(time);
                newItem->set_burstTime(f->get_rem());
                newItem->set_processNum(f->get_processNum());
                if (nFirst == NULL){nFirst=newItem;lastI = newItem;}
                else {lastI->set_next(newItem);lastI=lastI->get_next();}
                f->set_rem(0);
                if (f->get_next() != nullptr)
                newItem = new RR();
            }
            
            if (f->get_next() == nullptr) {
                f=first3;
                while (f != nullptr){
                    count+= f->get_rem();
                    f=f->get_next();
                    }
                if (count == 0 )finished=true;
                else {f=first3;newItem = new RR();count=0;}
                }
                
            else f=f->get_next();
                    }
                printBox d(nFirst);
                int i =0;
            f=first3;
        int departureTime=0;
        while (f != nullptr){
            departureTime+=(f->get_DepartureTime())-f->get_burstTime();
            f=f->get_next();
            i++;
            }
            AWT=float (departureTime)/float (i);
            cout <<"\nAverage Waiting Time is :" << AWT<<endl;
            }
            template <class S>
void else1 (S *s, S *ptr){
    
                    s->set_pre(ptr);
                    s->set_next(ptr->get_next());
                    ptr->set_next(s);
                    ptr=ptr->get_next();
                    if (ptr->get_next() != nullptr)
                    {
                    ptr=ptr->get_next();
                    ptr->set_pre(s);}
    
    }
                template <class K>
    void else2 (K *s,K *ptr){
        
        s->set_pre(ptr->get_pre());
                    s->set_next(ptr);
                    ptr=ptr->get_pre();
                    ptr->set_next(s);
                    ptr=ptr->get_next();
                    ptr=ptr->get_next();
                    ptr->set_pre(s);
        
        }
