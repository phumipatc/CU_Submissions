package lecture01_commonfeatures

object IfElseExample {
  def main(args: Array[String]): Unit = {
    var age = 15
    var x = 3;
    var message = ""
    if(age == 15){
      message = "age is 15"
      x += 1
    } else{
      message = "age is NOT 15"
      x -= 1
    }
    println(message)
    println(x)
  }
}
