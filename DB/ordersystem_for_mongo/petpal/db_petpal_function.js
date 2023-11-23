db.seller.aggregate([
    {
        $lookup: {
            from: "users",
            localField: "email",
            foreignField: "email",
            as: "users"
        }
    },
    {$unwind: "$users"},
    {
        $lookup: {
            from: "make_transaction",
            localField: "email",
            foreignField: "seller_email",
            as: "transaction"
        }
    },
    {$unwind: "$transaction"},
    {
        $lookup: {
            from: "animal",
            localField: "transaction.animal_id",
            foreignField: "animal_id",
            as: "animal"
        }
    },
    {$unwind: "$animal"},
    {
        $match: {"animal.is_sold": true}
    },
    {
        $group: {
            _id: { email: "$email", name: "$users.name" },
            total_sold_animals: { $sum: 1 },
            total_sales: { $sum: "$animal.price" }
        }
    },
    {$sort: { total_sales: -1 }},
    {$limit: 1}
])