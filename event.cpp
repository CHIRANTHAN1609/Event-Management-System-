#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class participant
{
string pid,pname,pusn,buffer;
public:
void unpack();
void read();
void read_file();
void write_file();
void display();
void pack();
int del(string);
void modify(string);
int search(string);
}p;
void participant::read()
{
cout<<"Enter details[pid,pname,pusn]\n";
cin>>pid>>pname>>pusn;
}
void participant::pack()
{
buffer.erase();
buffer+=pid+"|"+pname+"|"+pusn+"$\n";
}
void participant::read_file()
{
fstream fp;
fp.open("p.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof()&& buffer[0]!='*')
display();
}
fp.close();
}
void participant::unpack()
{
int i=0;
pid.erase();
while(buffer[i]!='|')
pid+=buffer[i++];
i++;
pname.erase();
while(buffer[i]!='|')
pname+=buffer[i++];
i++;
pusn.erase();
while(buffer[i]!='$')
pusn+=buffer[i++];
}
void participant::display()
{
cout<<"PID:"<<pid<<" PNAME:"<<pname<<" PUSN:"<<pusn<<endl;
}
int participant::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("p.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
if(buffer[0]!='*') //check the buffer ==*
recno++;
unpack();
if(pid==regno)
{
cout<<"\nRecord is "<<buffer;
cout<<"\nRecord Found at Position "<<recno<<"\n";
pos=fp.tellg();
flag=1;
 return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}
int participant::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("p.txt",ios::in|ios::out);
pos-=2;
t=fp.get();
while(t!='$'&&pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}
void coordinator::modify(string regno)
{
if(del(regno))
{
cout<<"\nEnter details[COORDINATORID,COORDINATORNAME,COORDINATORUSN] to modify\n";
cin>>coordinatorid>>coordinatorname>>cousn;
buffer.erase();
pack();
write_file();
}
}
void coordinator::write_file()
{
fstream fp;
fp.open("co.txt",ios::out|ios::app);
fp<<buffer;
fp.close();
}
class event
{
string eventid,coid,eventname,date,buffer;
public:
 void unpack();
 void read();
void read_file();
void write_file();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}s;
void event::read()
{
cout<<"Enter eventid,coid,eventname,date\n";
cin>>eventid>>coid>>eventname>>date;
}
void event::pack()
{
buffer.erase();
buffer+=eventid+"|"+coid+"|"+eventname+"|"+date+"$\n";
}
void event::read_file()
{
fstream fp;
fp.open("st.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof() && buffer[0]!='*')
display();
}
fp.close();
}
void event::unpack()
{
int i=0;
eventid.erase();
while(buffer[i]!='|')
eventid+=buffer[i++];
i++;
coid.erase();
while(buffer[i]!='|')
coid+=buffer[i++];
i++;
eventname.erase();
while(buffer[i]!='|')
eventname+=buffer[i++];
i++;
date.erase();
while(buffer[i]!='$')
date+=buffer[i++];
i++;
}
void event::display()
{
cout<<"EVENTID:"<<eventid<<"\t"<<"COORDINATORID:"<<coid<<"\t"<<"EVENTNAME:"<<eventname<<"\t"<<"DATE:"<<date<<endl;
}
int event::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("st.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
recno++;
unpack();
if(eventid==regno)
{
cout<<"\nRecordid "<<buffer;
cout<<"\nRecord is found at position "<<recno<<"\n";
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}
int event::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("st.txt",ios::in|ios::out);
pos-=2;
t=fp.get();
while(t!='$' && pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}
void event::modify(string regno)
{
if(del(regno))
{
cout<<"\n Enter details[EVENTID,COORDINATORID,EVENTNAME,DATE]to modify\n";
cin>>eventid>>coid>>eventname>>date;
buffer.erase();
pack();
write_file();
 }
}
void event::write_file()
{
fstream fp;
fp.open("st.txt",ios::out|ios::app);
fp<<buffer;
 fp.close();
 }
 class winner
{
string pid,eventid,coid,position,date,buffer; public:
void unpack();
void read();
void read_file();
void write_file();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}sa;
void winner::read()
{
cout<<"Enter pid,eventid,coid,position,date\n";
cin>>pid >>eventid>>coid>>position>>date;
}
void winner::pack()
{
buffer.erase();
buffer+= pid +"|"+eventid+"|"+coid+"|"+position+"|"+date+"$\n";
}
void winner::read_file()
{
fstream fp;
fp.open("s.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof() && buffer[0]!='*')
display();
}
fp.close();
}
void winner::unpack()
{
int i=0;
pid.erase();
while(buffer[i]!='|')
pid+=buffer[i++]; i++;
eventid.erase();
while(buffer[i]!='|')
eventid+=buffer[i++];
i++;
coid.erase();
while(buffer[i]!='|')
coid+=buffer[i++];
i++;
position.erase();
while(buffer[i]!='|')
position+=buffer[i++];
i++;
date.erase();
while(buffer[i]!='$')
date+=buffer[i++];
i++;
}
void winner::display()
{
cout<<"PARTICIPANTID:"<< pid;
<<"\t"<<"EVENTID:"<<eventid<<"\t"<<"COORDINATORID:"<<coid<<"\t"<<"POSITION:"<<position<<"\t"<<"DATE:"<<date<<endl;
}
int winner::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("s.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
recno++;
unpack();
if(pid ==regno)
{
cout<<"\n Record id "<<buffer;
cout<<"\nRecord is found at position "<<recno<<"\n";
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}
 int winner::del(string regno)
 {
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("s.txt",ios::in|ios::out);
pos-=2;
t=fp.get();
while(t!='$' && pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
 if(!flag)

return 0;
else
return 1;
}
void winner::modify(string regno)
{
if(del(regno))
{
cout<<"\n Enter details[PARTICIPANTID,EVENTID,COORDINATORID,POSITION,DATE] to modify\n";
cin>> pid >>eventid>>coid>>position>>date;
buffer.erase();
pack();
write_file();
}
}
void winner::write_file()
{
fstream fp;
fp.open("s.txt",ios::out |ios::app);
fp<<buffer;
fp.close();
}
