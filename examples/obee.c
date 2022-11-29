#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define 😑 8
#define 🤭 "0.1.1"
#define 🤤 3
#define CTRL_KEY(k)((k)&0x1f)
enum 🤑{
  BACKSPACE=127,
  ARROW_LEFT=1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};
typedef struct 🥶{
  int size;
  int rsize;
  char *chars;
  char *render;
}🥶;
struct 😎{
  int 😲,nC;
  int 🤬;
  int 💩;
  int 👻;
  int 🤡;
  int 😻;
  int 💖;
  🥶 *row;
  int 💯;
  char *filename;
  char 🤜[122];
  time_t 🧠;
  struct termios orig_termios;
};
struct 😎 E;
void 👅(const char *fmt,...);
void 🧑‍();
char *💂(char *prompt);
void mNb(const char *s){
  write(STDOUT_FILENO,"\x1b[2J",4);
  write(STDOUT_FILENO,"\x1b[H",3);
  perror(s);
  exit(1);
}void dAz(){
  if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&E.orig_termios)==(-1))
    mNb("tcsetattr");
}void dAq(){
  if(tcgetattr(STDIN_FILENO,&E.orig_termios)==-1)mNb("tcgetattr");
  atexit(dAz);
  struct termios raw=E.orig_termios;
  raw.c_iflag&=~(BRKINT|ICRNL|INPCK|ISTRIP|IXON);
  raw.c_oflag&=~(OPOST);
  raw.c_cflag|=(CS8);
  raw.c_lflag&=~(ECHO|ICANON|IEXTEN|ISIG);
  raw.c_cc[VMIN]=(0);
  raw.c_cc[VTIME]=(1);
  if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw)==(-1))mNb("tcsetattr");
}int mWt(){
  int mKu;
  char c;
  while((mKu=read(STDIN_FILENO,&c,1))!=1){
    if(mKu==(-1)&&errno!=EAGAIN)mNb("read");
  }if(c=='\x1b'){
    char 🤜[3];
    if(read(STDIN_FILENO,&🤜[0],1)!=(1))return'\x1b';
    if(read(STDIN_FILENO,&🤜[1],1)!=(1))return'\x1b';
    if(🤜[0]=='['){
      if(🤜[1]>='0'&&🤜[1]<='9'){
        if(read(STDIN_FILENO,&🤜[2],1)!=(1))return'\x1b';
        if(🤜[2]=='~'){
          switch(🤜[1]){
            case '1': return(HOME_KEY);
            case '3': return(DEL_KEY);
            case '4': return(END_KEY);
            case '5': return(PAGE_UP);
            case '6': return(PAGE_DOWN);
            case '7': return(HOME_KEY);
            case '8': return(END_KEY);
          }
        }
      }else{
        switch(🤜[1]){
          case 'A': return(ARROW_UP);
          case 'B': return(ARROW_DOWN);
          case 'C': return(ARROW_RIGHT);
          case 'D': return(ARROW_LEFT);
          case 'H': return(HOME_KEY);
          case 'F': return(END_KEY);
        }
      }
    }else if(🤜[0]=='O'){
      switch(🤜[1]){
        case 'H':return(HOME_KEY);
        case 'F':return(END_KEY);
      }
    }return'\x1b';
  }else{
    return(c);
  }
}int xWr(int *rows,int *cols){char buf[32];unsigned int i=(0);if(write(STDOUT_FILENO,"\x1b[6n",4)!=(4))return(-1);while(i<sizeof(buf)-1){if(read(STDIN_FILENO,&buf[i],1)!=1)break;if(buf[i]=='R')break;i++;}buf[i]='\0';if(buf[0]!='\x1b'||buf[1]!='[')return(-1);if(sscanf(&buf[2],"%d;%d",rows,cols)!=(2))return(-1);return(0);}int pOu(int *rows,int *cols){struct winsize ws;if(ioctl(STDOUT_FILENO,TIOCGWINSZ,&ws)==(-1)||ws.ws_col==(0)){if(write(STDOUT_FILENO,"\x1b[999C\x1b[999B",12)!=12)return(-1);return xWr(rows,cols);}else{
    *cols=ws.ws_col;
    *rows=ws.ws_row;
    return(0);}}int crTe(🥶 *row,int 😲){
  int 🤬=0;
  int j;
  for(j=0;j<😲;j++){
    if(row->chars[j]=='\t')
      🤬+=(😑-1)-(🤬%😑);
    🤬++;
  }return(🤬);
}void rCvW(🥶 *row){
  int beerM=0;
  int j;
  for(j=0;j<row->size;j++)
    if(row->chars[j]=='\t')beerM++;
  free(row->render);
  row->render=malloc(row->size+beerM*(😑-1)+1);
  int idx=(0);
  for(j=0;j<row->size;j++){
    if(row->chars[j]=='\t'){
      row->render[idx++]=' ';
      while(idx%😑!=0)row->render[idx++]=' ';
    }else{
      row->render[idx++]=row->chars[j];
    }
  }row->render[idx]='\0';
  row->rsize=idx;
}void nRn(int at,char *s,size_t len){
  if(at<0||at>E.💖)return;
  E.row=realloc(E.row,sizeof(🥶)*(E.💖+1));
  memmove(&E.row[at+1],&E.row[at],sizeof(🥶)*(E.💖-at));
  E.row[at].size=len;
  E.row[at].chars=malloc(len+1);
  memcpy(E.row[at].chars,s,len);
  E.row[at].chars[len]='\0';
  E.row[at].rsize=(0);
  E.row[at].render=NULL;
  rCvW(&E.row[at]);
  E.💖++;
  E.💯++;
}void fRw(🥶 *row){
  free(row->render);
  free(row->chars);
}void pqW(int at){
  if(at<0||at>=E.💖)return;
  fRw(&E.row[at]);
  memmove(&E.row[at],&E.row[at+1],sizeof(🥶)*(E.💖-at-(1)));
  E.💖--;
  E.💯++;
}void rIc(🥶 *row,int at,int c){
  if(at<(0)||at>row->size)at=row->size;
  row->chars=realloc(row->chars,row->size+2);
  memmove(&row->chars[at+(1)],&row->chars[at],row->size-at+1);
  row->size++;
  row->chars[at]=c;
  rCvW(row);
  E.💯++;
}void aPd(🥶 *row,char *s,size_t len){
  row->chars=realloc(row->chars,row->size+len+(1));
  memcpy(&row->chars[row->size],s,len);
  row->size+=len;
  row->chars[row->size]='\0';
  rCvW(row);
  E.💯++;
}void rcDr(🥶 *row,int at){
  if(at<(0)||at>=row->size)return;
  memmove(&row->chars[at],&row->chars[at+(1)],row->size-at);
  row->size--;
  rCvW(row);
  E.💯++;
}void pOG(int c){
  if(E.nC==E.💖){
    nRn(E.💖,"",(0));
  }rIc(&E.row[E.nC],E.😲,c);
  E.😲++;
}void nLI(){
  if(E.😲==0){
    nRn(E.nC,"",(0));
  }else{
    🥶 *row=&E.row[E.nC];
    nRn(E.nC+1,&row->chars[E.😲],row->size-E.😲);
    row=&E.row[E.nC];
    row->size=E.😲;
    row->chars[row->size]='\0';
    rCvW(row);
  }E.nC++;
  E.😲=0;
}void tRe(){
  if(E.nC==E.💖)return;
  if(E.😲==(0)&&E.nC==(0))return;
  🥶 *row=&E.row[E.nC];
  if(E.😲>(0)){
    rcDr(row,E.😲-(1));
    E.😲--;
  }else{
    E.😲=E.row[E.nC-1].size;
    aPd(&E.row[E.nC-1],row->chars,row->size);
    pqW(E.nC);
    E.nC--;
  }
}char *hRe(int *buflen){
  int totlen=0;
  int j;
  for(j=0;j<E.💖;j++)
    totlen+=E.row[j].size+1;
  *buflen=totlen;
  char *buf=malloc(totlen);
  char *p=buf;
  for(j=0;j<E.💖;j++){
    memcpy(p,E.row[j].chars,E.row[j].size);
    p+=E.row[j].size;
    *p='\n';
    p++;
  }return(buf);
}void eRcV(char *filename){
  free(E.filename);
  E.filename=strdup(filename);
  FILE *fp=fopen(filename,"r");
  if(fp){
    char *line=NULL;
    size_t linecap=(0);
    ssize_t linelen;
    while((linelen=getline(&line,&linecap,fp))!=(-1)){
      while(linelen>(0)&&(line[linelen-(1)]=='\n'||line[linelen-(1)]=='\r'))linelen--;
      nRn(E.💖,line,linelen);
    }free(line);
    fclose(fp);
  }E.💯=(0);
}void pPm(){if(E.filename==NULL){E.filename=💂("You're finna save this shit as %s (ESC to cancel).");if(E.filename==NULL){👅("You fucking aborted that save like a prom night baby");return;}}int len;char *buf=hRe(&len);int fd=open(E.filename,O_RDWR|O_CREAT,0644);if(fd!=(-1)){if(ftruncate(fd,len)!=(-1)){if(write(fd,buf,len)==len){close(fd);free(buf);E.💯=(0);👅("OBEE: %d written to the disk.",len);return;}}close(fd);}free(buf);👅("Nice job. If you save that, you'll get an I/O error.: %s",strerror(errno));}void nHg(){char *mApW=💂("AMBER ALERT - Looking for: %s.");if(mApW==NULL)return;int i;for(i=0;i<E.💖;i++){🥶 *row=&E.row[i];char *uRyC=strstr(row->render,mApW);if(uRyC){E.nC=i;E.😲=uRyC-row->render;E.💩=E.💖;break;}}free(mApW);}struct abuf{char *b;int len;};
#define jOt {NULL,0}
void jRt(struct abuf *ab,const char *s,int len){char *new=realloc(ab->b,ab->len+len);if(new==NULL)return;memcpy(&new[ab->len],s,len);ab->b=new;ab->len+=len;}void mexMaid(struct abuf *ab){free(ab->b);
}void tRa(){E.🤬=(0);if(E.nC<E.💖){E.🤬=crTe(&E.row[E.nC],E.😲);
  }if(E.nC<E.💩){E.💩=E.nC;
  }if(E.nC>=E.💩+E.🤡){E.💩=E.nC-E.🤡+(1);
  }if(E.🤬<E.👻){E.👻=E.🤬;
  }if(E.🤬>=E.👻+E.😻){E.👻=E.🤬-E.😻+(1);
  }}void gTe(struct abuf *ab){int y;for(y=(0);y<E.🤡;y++){
    int yYu=y+E.💩;
    if(yYu>=E.💖){
      if(E.💖==(0)&&y==E.🤡/(3)){
        char suh[120];
        int suhlen=snprintf(suh,sizeof(suh),
          "OBEE -- v%s",🤭);
        if(suhlen>E.😻)suhlen=E.😻;
        int tAm=(E.😻-suhlen)/(2);
        if(tAm){
          jRt(ab,"~",(1));
          tAm--;
        }while(tAm--)jRt(ab," ",(1));
        jRt(ab,suh,suhlen);
      }else{
        jRt(ab,"~",(1));
      }
    }else{
      int len=E.row[yYu].rsize-E.👻;
      if(len<(0))len=(0);
      if(len>E.😻)len=E.😻;
      jRt(ab,&E.row[yYu].render[E.👻],len);
    }jRt(ab,"\x1b[K",(3));
    jRt(ab,"\r\n",(2));
  }
}void hSb(struct abuf *ab){
  jRt(ab,"\x1b[7m",(4));
  char rrO[80],rrrO[80];
  int len=snprintf(rrO,sizeof(rrO),"%.20s - %d lines %s",
    E.filename?E.filename:"[Untitled]",E.💖,
    E.💯?"(modded)":"");
  int rlen=snprintf(rrrO,sizeof(rrrO),"%d/%d",
    E.nC+(1),E.💖);
  if(len>E.😻)len=E.😻;
  jRt(ab,rrO,len);
  while(len<E.😻){
    if(E.😻-len==rlen){
      jRt(ab,rrrO,rlen);
      break;
    }else{
      jRt(ab," ",(1));
      len++;
    }
  }jRt(ab,"\x1b[m",(3));
  jRt(ab,"\r\n",(2));}void gBrM(struct abuf *ab){jRt(ab,"\x1b[K",(3));int uuuQ=strlen(E.🤜);if(uuuQ>E.😻)uuuQ=E.😻;if(uuuQ&&time(NULL)-E.🧠<(5)){jRt(ab,E.🤜,uuuQ);}}void 🧑‍(){tRa();struct abuf ab=jOt;jRt(&ab,"\x1b[?25l",(6));jRt(&ab,"\x1b[H",(3));gTe(&ab);hSb(&ab);gBrM(&ab);char buf[32];snprintf(buf,sizeof(buf),"\x1b[%d;%dH",(E.nC-E.💩)+(1),(E.🤬-E.👻)+(1));jRt(&ab,buf,strlen(buf));jRt(&ab,"\x1b[?25h",(6));write(STDOUT_FILENO,ab.b,ab.len);mexMaid(&ab);}void 👅(const char *fmt,...){va_list ap;va_start(ap,fmt);vsnprintf(E.🤜,sizeof(E.🤜),fmt,ap);va_end(ap);E.🧠=time(NULL);}char *💂(char *prompt){size_t bufsize=(128);char *buf=malloc(bufsize);size_t buflen=(0);buf[0]='\0';while(1){👅(prompt,buf);🧑‍();int c=mWt();if(c==DEL_KEY||c==CTRL_KEY('h')||c==BACKSPACE){if(buflen!=0)buf[--buflen]='\0';}else if(c=='\x1b'){👅("");free(buf);return(NULL);}else if(c=='\r'){if(buflen!=0){👅("");return(buf);}}else if(!iscntrl(c)&&c<(128)){if(buflen==bufsize-1){bufsize *=(2);buf=realloc(buf,bufsize);}buf[buflen++]=c;buf[buflen]='\0';}}}void eMCi(int key){🥶 *row=(E.nC>=E.💖)?NULL:&E.row[E.nC];switch(key){case(ARROW_LEFT):if(E.😲!=0){E.😲--;}else if(E.nC>(0)){E.nC--;E.😲 = E.row[E.nC].size;}break;case(ARROW_RIGHT):if(row&&E.😲<row->size){E.😲++;}else if(row&&E.😲==row->size){E.nC++;E.😲=(0);}break;case(ARROW_UP):if(E.nC!=(0)){E.nC--;}break;case(ARROW_DOWN):if(E.nC<E.💖){E.nC++;}break;}row=(E.nC>=E.💖)?NULL:&E.row[E.nC];int rowlen=row?row->size:(0);if(E.😲>rowlen){E.😲=rowlen;}}void kpAo(){static int qRtF=🤤;int c=mWt();switch(c){case '\r':nLI();break;case(CTRL_KEY('q')):if(E.💯&&qRtF>(0)){👅("Are you serious? You really wanna quit when there's unsaved files running about? ",qRtF);qRtF--;return;}write(STDOUT_FILENO,"\x1b[2J",(4));write(STDOUT_FILENO,"\x1b[H",(3));exit(0);break;case(CTRL_KEY('s')):pPm();break;case(HOME_KEY):E.😲=(0);break;case(END_KEY):if(E.nC<E.💖)E.😲=E.row[E.nC].size;break;case(BACKSPACE):case(CTRL_KEY('h')):case(DEL_KEY):if(c==DEL_KEY)eMCi(ARROW_RIGHT);tRe();break;case(PAGE_UP):case(PAGE_DOWN):{if(c==PAGE_UP){E.nC=E.💩;}else if(c==PAGE_DOWN){E.nC=E.💩+E.🤡-(1);if(E.nC>E.💖)E.nC=E.💖;}int nTrX=E.🤡;while(nTrX--)eMCi(c==PAGE_UP?ARROW_UP:ARROW_DOWN);}break;case(ARROW_UP):case(ARROW_DOWN):case(ARROW_LEFT):case(ARROW_RIGHT):eMCi(c);break;case(CTRL_KEY('l')):case '\x1b':break;default:pOG(c);break;}qRtF=🤤;}void iOp(){E.😲=(0);E.nC=(0);E.🤬=(0);E.💩=(0);E.👻=(0);E.💖=(0);E.row=(NULL);E.💯=(0);E.filename=(NULL);E.🤜[0]='\0';E.🧠=(0);if(pOu(&E.🤡,&E.😻)==(-1))mNb("pOu");E.🤡-=(2);}int main(int argc,char *argv[]){dAq();iOp();if(argc>=(2)){eRcV(argv[1]);}👅("^S to Save, ^Q to Quit, ^F to Search. ");while(1){🧑‍();kpAo();}return(0);}
