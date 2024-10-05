{Radu Visinescu; 100 puncte}
program concurs;
var f,g:text;
    judet, nrmat:array[1..500]of integer;
    l,p,u:array[1..50]of integer;
    nj,n,i,j,p1,p2,aux,nr,poz,max,max1,max2:integer;
begin
assign(f,'concurs.in');
reset(f);
readln(f,nr);
for i:=1 to nr do readln(f,judet[i],nrmat[i]);
close(f);
assign(g,'concurs.out');
rewrite(g);

for i:=1 to nr-1 do
 for j:=i+1 to nr do
     if (judet[i]>judet[j]) or (judet[i]=judet[j])and(nrmat[i]>nrmat[j]) then
        begin
        aux:=judet[i];
        judet[i]:=judet[j];
        judet[j]:=aux;
        aux:=nrmat[i];
        nrmat[i]:=nrmat[j];
        nrmat[j]:=aux;
        end;
poz:=1;i:=1;
while (poz<=nr) do begin
p[i]:=poz;
while (poz+1<=nr)and(judet[poz]=judet[poz+1]) do
      poz:=poz+1;
u[i]:=poz;
inc(i);
inc(poz);
end;
nj:=i-1;
writeln(g,nj);
for i:=1 to nj do begin l[i]:=u[i]-p[i]+1;write(g,l[i],' '); end;
writeln(g);

repeat
max1:=-1;max2:=-1;
for i:=1 to nj do
  if l[i]>max1 then begin max1:=l[i];p1:=i end;
for i:=1 to nj do
  if (i<>p1)and(max2<l[i]) then begin max2:=l[i];p2:=i end;
if (max1>0)and(max2>0) then
     begin
     writeln(g,judet[p[p1]],' ',nrmat[p[p1]]);
     writeln(g,judet[p[p2]],' ',nrmat[p[p2]]);
     inc(p[p1]);
     inc(p[p2]);
     dec(l[p1]);
     dec(l[p2]);
     end
     else if (max1>0) then
     begin
     writeln(g,judet[p[p1]],' ',nrmat[p[p1]]);
     inc(p[p1]);
     dec(l[p1]);
     end;
max:=0;
for i:=1 to nj do if l[i]>max then max:=l[i];
until max=0;
close(g);
end.
