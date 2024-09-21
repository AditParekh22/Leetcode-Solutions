
SELECT p.product_id, IFNULL(round(SUM(p.price*u.units)/SUM(u.units), 2),0) as average_price
FROM 
Prices AS p
LEFT JOIN
UnitsSold AS u
ON
p.product_id  = u.product_id AND 
u.purchase_date BETWEEN p.Start_date and p.end_date
GROUP BY
p.product_id 