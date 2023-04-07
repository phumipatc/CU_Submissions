package lecture01_commonfeatures

object helloWorld {
  def main(args: Array[String]): Unit = {
    var name = "Tanjiro"
    var age  = 15.5
    //println("Hello "  + name + ", age =" + age)
    //println(s"$name is $age years old.")
    //println(f"$name%s is $age%d years old.")
    println("Kamado \nNezuko")
    println(raw"Kamado \nNezuko")

  }
}
