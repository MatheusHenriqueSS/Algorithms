//subarrays <=L
const int mxl=30;
struct node{
  node *l,*r;
  int sz;
  node(){
    l=r=NULL;
    sz=0;
  }
  void add(int x,int H=mxl){
    if(H==-1){
      sz++;
      return;
    }
    if(x&(1<<H)){
      if(!r)r=new node();
      r->add(x,H-1);
    }
    else{
      if(!l)l=new node();
      l->add(x,H-1);
    }
    sz=Sz(l)+Sz(r);

  }
  int Sz(node *no){
    return !no?0:no->sz;
  }
  int cnt(int x,int L,int H=mxl){
    if(!sz)return 0;
    if(H==-1)return sz;
    if(x&(1<<H)){
      if(L&(1<<H)){
        return Sz(r)+(!l?0:l->cnt(x,L,H-1));
      }
      return !r?0:r->cnt(x,L,H-1);
    }
    else{
      if(L&(1<<H)){
        return Sz(l)+(!r?0:r->cnt(x,L,H-1));
      }
      return !l?0:l->cnt(x,L,H-1);
    }
  }
};
