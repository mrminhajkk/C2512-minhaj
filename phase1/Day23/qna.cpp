int a,b;
cout << enter 2 numbers
cin>> a;
cin >> b;
 char op;
 cout<< enter the operator like + ,- ,* ,/
 cin >> op



 switch (op){
    case '+':
    cout << a+b
    break;


case '-':
    cout << a-b
    break;

    case '*':
    cout << a*b
    break;

    case '/':
    if (b==0){
        cout << error! dividing byzerio is not allowed
    }
    
    cout << a/b
    break;
    default:
    cout << invalidoperator
 break;
 }




 2
select Customerid 
from Orders
where TotalAmount > 500
groupby CustomerId 
having count(OrderId)=3;


3
