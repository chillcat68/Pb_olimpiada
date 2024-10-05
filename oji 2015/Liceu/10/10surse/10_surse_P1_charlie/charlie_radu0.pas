{
	Sursa 5p - backtracking (scop didactic)
	prof. Radu Visinescu, Ploiesti
}
var fin,fout:text;
    s:string;
    st:array[1..1000]of string;
    valoare:array[1..1000]of integer;
    k,p,i,max:integer;save:string;
    p2,u,save_p,save_u,d,dmax:integer;
function nu_exista(s:string):boolean;
var i:integer;
begin
nu_exista:=true;
for i:=1 to length(s)-2 do
 if  (ord(s[i])>ord(s[i+1])) and (ord(s[i+1])<ord(s[i+2])) then
  nu_exista:=false;
end;
procedure eliminare(s:string;v:integer);
var p:string;max:integer;
i:integer;
begin
if nu_exista(s) then begin k:=k+1;st[k]:=s; valoare[k]:=v;end
else
 for i:=1 to length(s)-2 do
	if (ord(s[i])>ord(s[i+1])) and (ord(s[i+1])<ord(s[i+2])) then
		begin
		p:=s;
		delete(p,i+1,1);
                max:=ord(s[i])-ord('a')+1;
                if max<ord(s[i+2])-ord('a')+1 then
                   max:=ord(s[i+2])-ord('a')+1;
                eliminare(p,v+max);
		end;
end;

begin
assign(fin,'charlie.in');
reset(fin);
assign(fout,'charlie.out');
rewrite(fout);
readln(fin,p);
readln(fin,s);
k:=0;
if p=2 then begin
            eliminare(s,0);
            max:=-1;
            for i:=1 to k do
             if max<valoare[i] then
               begin
               max:=valoare[i];
               save:=st[i];
               end;
            writeln(fout,save);
            writeln(fout,max);
            end
else begin
     dmax:=1;save_p:=1;save_u:=1;
     p2:=1;u:=1;
     d:=1;
     i:=1;
     while (i<=length(s)-2)    do
      if ((ord(s[i])>ord(s[i+1])) and (ord(s[i+1])<ord(s[i+2])))       then
       begin
           u:=i+2;i:=i+2;
           d:=u-p2+1;
           if (dmax<d)then begin save_p:=p2;save_u:=u;dmax:=save_u-save_p+1; end
       end
      else begin i:=i+2;p2:=i;u:=i;end;
      p2:=2;u:=2;
      d:=1;
      i:=2;
     while (i<=length(s)-2)      do
      if ((ord(s[i])>ord(s[i+1])) and (ord(s[i+1])<ord(s[i+2])))          then
       begin
           u:=i+2;i:=i+2;
           d:=u-p2+1;
           if (dmax<d) then begin save_p:=p2;save_u:=u;dmax:=save_u-save_p+1; end
       end
      else begin i:=i+2;p2:=i;u:=i;end;
     writeln(fout,save_u-save_p+1);
	 end;

close(fin);
close(fout);
end.
