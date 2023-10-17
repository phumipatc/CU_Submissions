SELECT customer_id, customer_name
FROM customer NATURAL JOIN (
	SELECT customer_id, COUNT(*) AS number_of_orders
	FROM ordert
	GROUP BY customer_id
) AS counted
GROUP BY customer_id, customer_name
HAVING MAX(number_of_orders) = (
	SELECT MAX(number_of_orders)
	FROM (
		SELECT COUNT(*) AS number_of_orders
		FROM ordert
		GROUP BY customer_id
	) AS counted
)
;

-- SELECT customer_id, customer_name, number_of_orders
-- FROM customer NATURAL JOIN (
	-- SELECT customer_id, COUNT(*) AS number_of_orders
	-- FROM ordert
	-- GROUP BY customer_id
-- ) AS counted
-- ORDER BY number_of_orders DESC
-- LIMIT 1
-- ;