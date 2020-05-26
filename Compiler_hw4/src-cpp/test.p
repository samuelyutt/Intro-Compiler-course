//&S-
//&T-

test;
// no global declaration(s)

func(a : integer ; b : array 1 to 2 of array 2 to 4 of real) : real;
begin
    var c : "hello world!";
    begin
        var d : array 1 to 2 of array 10 to 20 of real;
        d := 2 > 5;
        return d[1][5][7];
    end
end
end func

begin
    var a : array 1 to 2 of array 4 to 4 of real;
    begin
        var a : boolean;  // outer 'a' has been hidden in this scope
        //return (weqde[1][4] >= 1.0);
    end
end
end test
