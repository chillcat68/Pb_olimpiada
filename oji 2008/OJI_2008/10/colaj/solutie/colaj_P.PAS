{prof. Carmen Minca}
program colaj;
type vect=array[1..210] of integer;
type dr=record
        pa,pb,pc,pd,a,b,c,d:integer
        end;
var a:array[0..210,0..210]of byte;
    x,y:vect;
    n,m,p,k,nr,x0,y0,nl,nc:integer;
    g:text;
    v:array[1..105] of dr;


function ver(i,xa,xb,xc,xd:integer):byte;
var j:integer;
begin
  ver:=1;
  for j:=1 to i do
   if (v[j].a<xa)and(v[j].b<xb)and(v[j].c>xc)and(v[j].d>xd)then begin ver:=0; break; end;
end;

procedure citire;
var i,xa,xb,xc,xd,r:integer;
    f:text;
begin
assign(f,'colaj.in');
reset(f);
readln(f,n);
readln(f,m,p);
x0:=1; y0:=1;  k:=0; r:=0;
for i:=1 to n do
 begin
  readln(f,xa,xb,xc,xd);
  if ver(r,xa,xb,xc,xd)=1 then
  begin inc(r);
    v[r].a:=xa; v[r].b:=xb; v[r].c:=xc; v[r].d:=xd;
    inc(k); x[k]:=v[r].a; y[k]:=v[r].b;
    inc(k); x[k]:=v[r].c; y[k]:=v[r].d;
    if (v[r].a=0) or (v[r].c=0) then dec(x0);
    if (v[r].b=0) or (v[r].d=0) then dec(y0);
  end;
 end;
 n:=r;
 close(f)
end;

function poz(var z:vect; i,j:integer):integer;
var t,ind,s:integer;
 begin t:=-1;
  while i<j do
  begin
   ind:=0;
   if z[i]>z[j] then
      begin ind:=1; s:=z[i]; z[i]:=z[j]; z[j]:=s; end;
   if ind<>0 then
      begin if t=-1 then inc(i)
                    else dec(j);
            t:=-t;
      end
      else if t=-1 then dec(j)
                   else inc(i);
  end;
  poz:=i;
end;

procedure dv(var z:vect; s,d:integer);
var t:integer;
begin if d>s then
       begin t:=poz(z,s,d);
             dv(z,s,t-1); dv(z,t+1,d)
       end;
end;

function caut(z:vect; a:integer):integer;
var i,j,t,ind:integer;
begin i:=1; j:=k; ind:=0;
   while (i<=j)and(ind=0) do
    begin t:=(i+j) div 2;
          if z[t]=a then begin i:=t; ind:=1; end
          else if a<z[t] then j:=t-1
                         else i:=t+1;
    end;
    caut:=i;
end;

procedure pozitii;
var i:integer;
begin
  for i:=1 to n do
  begin v[i].pa:=caut(x,v[i].a);
        v[i].pb:=caut(y,v[i].b);
        v[i].pc:=caut(x,v[i].c);
        v[i].pd:=caut(y,v[i].d)
  end
end;

procedure matrice;
var i,j,t:integer;
begin
 for t:=1 to n do
  for j:=v[t].pa to v[t].pc-1 do
   for i:=v[t].pb to v[t].pd-1 do a[i+y0,j+x0]:=1;
end;

procedure bordare;
var i,j:integer;
begin
 nl:=y0+2*n-1;
 nc:=x0+2*n-1;
 if m>x[k] then inc(nc);
 if p>y[k] then inc(nl);
 for i:= 0 to nl+1 do
   begin a[i,0]:=1; a[i,nc+1]:=1; end;
 for i:= 0 to nc+1 do
   begin a[0,i]:=1; a[nl+1,i]:=1; end;
end;

procedure fill(i,j:integer);
begin
 a[i,j]:=1;
 if a[i,j-1]=0 then fill(i,j-1);
 if a[i,j+1]=0 then fill(i,j+1);
 if a[i-1,j]=0 then fill(i-1,j);
 if a[i+1,j]=0 then fill(i+1,j);
end;

procedure supr;
var i,j:integer;
begin for i:=1 to nl do
       for j:=1 to nc do
        if a[i,j]=0 then begin inc(nr);fill(i,j);end;
end;

Begin
citire;
dv(x,1,k); dv(y,1,k);
pozitii;
matrice;
bordare;
supr;
assign(g,'colaj.out');
rewrite(g);
writeln(g,nr);
close(g);
end.
