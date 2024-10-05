Program Dominant;

Const DIM = 300010;

Var  S: array[1..DIM] of char;
     D: array[-DIM..DIM] of longint;
     F: array[-DIM..DIM] of longint;
     V, n, i, maxim, sc, nr, sum: longint;
     fin, fout:text;

begin
    assign(fin, 'dominant.in');
    assign(fout,'dominant.out');
    reset(fin); rewrite(fout);
    readln(fin,V);

    //memset(f, -1, sizeof(f));
    for i := -DIM to DIM do F[i] := -1;
    i:=0;
    while not eof(fin) do begin
        inc(i);
        read(fin, S[i]);
    end;
    close(fin);
    F[0] := 0;   // F[i] = indicele primei aparitii a sumei i
    D[0] := 0;   // D[i] = pozitia de inceput a unei secvente ce se termina cu suma i

    sum := 0;
    for i:=1 to length(S) do begin
        if S[i] = '1' then
            inc(sum)
        else
            dec(sum);

        if F[sum] = -1 then begin
            F[sum] := i;

            if F[sum - 1] <> -1 then
                D[sum] := D[sum-1] + i - F[sum-1]
            else
                D[sum] := 0;

        end;

        if F[sum-1] <> -1 then begin
            sc := D[sum-1] + i - F[sum-1];
            if sc > maxim then begin
                maxim := sc;
                nr := 1;
            end
                else if sc = maxim then inc(nr);
        end

    end;
    if V = 1 then
        writeln(fout, maxim)
    else
        writeln(fout, nr);
    close(fout)
end.
