SELECT SUM(payment) AS total_payment
FROM (
	SELECT ordered_quantity * standard_price AS payment
	FROM order_line NATURAL JOIN product
	WHERE order_id = 3
) AS allpayment
;