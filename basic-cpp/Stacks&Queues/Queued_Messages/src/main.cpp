#include <iostream>
#include "queue2.h"
using namespace std;

class Date{
    private:
        int second, minute, hour, day,month,year;
    public:

        Date(){}
        Date(int second, int minute, int hour, int day, int month, int year){
            this->second=second;
            this->minute=minute;
            this->hour=hour;
            this->day=day;
            this->month=month;
            this->year=year;
        }

        int getSecond(){
            return second;
        }
        int getMinute(){
            return minute;
        }
        int getHour(){
            return hour;
        }
        int getDay(){
            return day;
        }
        int getMonth(){
            return month;
        }
        int getYear(){
            return year;
        }
//
//        string toString(){
//        return " "+string(hour)+" : "+string(minute)+" : "+string(second)+" || "+string(year)+" - "+string(month)+" - "+string(day));
//        }

        bool compare_dates(Date d){
            int own_details[6]={second, minute, hour, day, month, year};
            int d_details[6]={d.getSecond(),d.getMinute(),d.getHour(), d.getDay(), d.getMonth(), d.getYear()};
            for (int i = 5; i >= 0 ;i--)
                {
                    if(d_details[i]<own_details[i]){
                        return 0;//own_date is younger
                    }
                    else{
                        return 1;//own_date is older
                    }
                }
        }
};



class Message{
    private:
        char* expediteur, *destinataire, *contenu;
        Date date;
    public:
        Message(){}
        Message(char* expediteur, char* destinataire, char* contenu, Date date){
            this->expediteur=expediteur;
            this->destinataire=destinataire;
            this->contenu=contenu;
            this->date=date;
        }

        void getContents(){
            printf("Message was sent by: %s to %s on %d:%d:%d %d-%d-%d Contents : %s\n",expediteur,destinataire,date.getHour(),date.getMinute(),date.getSecond(),date.getYear(),date.getMonth(),date.getDay(),contenu);
        }
};

class MessageSender{
    private:
        Message message;
        bool stream_is_empty=1;
    public:
        MessageSender(){};
        MessageSender(Message m){
            this->message=m;
            stream_is_empty=0;
        }
        void thisMessage(Message m){
            message=m;
        }

        void putMessage(Queue <Message> &q){
            q.enqueue(message);
        }
};

class MessageReceiver{
    public:
        MessageReceiver(){}
         void popMessage(Queue <Message> &q){
            cout<<" Message received: ";
            q.peek().getContents();
            q.dequeue();
        }
};



int main()
{
    Queue <Message> q;
    Message m1("Grama Ioan-Emanuel", "Grama Gligore-Ioan", "Hello World!",Date(1,1,1,20,11,1998));
    Message m2("Grama Ioan-Emanuel", "Grama Gligore-Ioan", "Almost!",Date(2,1,1,20,11,1998));
    Message m3("Grama Ioan-Emanuel", "Grama Gligore-Ioan", "Working!",Date(3,1,1,20,11,1998));

    MessageSender sender;
    MessageReceiver receiver;

    sender.thisMessage(m1); //sends the message
    sender.putMessage(q);// enqueues the messages

    sender.thisMessage(m2);// sends another message
    sender.putMessage(q);// enqueues the second message

    sender.thisMessage(m3);
    sender.putMessage(q);

    receiver.popMessage(q); // dequeues the message
    receiver.popMessage(q);



}
