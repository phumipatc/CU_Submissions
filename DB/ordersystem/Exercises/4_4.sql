SELECT product_id, product_description
FROM order_line NATURAL JOIN product
GROUP BY product_id, product_description
HAVING COUNT(product_id) = (
	SELECT MAX(count_product)
	FROM (
		SELECT COUNT(product_id) AS count_product
		FROM order_line
		GROUP BY product_id
	) AS counted
)
;