SELECT product_id, product_description
FROM order_line NATURAL JOIN product
GROUP BY product_id, product_description
HAVING SUM(ordered_quantity) = (
	SELECT MAX(count_order)
	FROM (
		SELECT SUM(ordered_quantity) AS count_order
		FROM order_line
		GROUP BY product_id
	) AS counted
)
;