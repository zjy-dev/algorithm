CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = N - 1;

    return(
        select
            distinct salary
        from
            employee
        order by
            salary desc
        limit n, 1
    );
END