SELECT customer_id, customer_name
FROM ordert NATURAL JOIN customer
WHERE order_date >= '2020-01-10' AND order_date < '2020-01-16'
GROUP BY customer_id, customer_name
;