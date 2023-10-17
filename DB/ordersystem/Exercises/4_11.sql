SELECT customer_id, customer_name
FROM customer
WHERE customer_id NOT IN (SELECT customer_id FROM ordert);