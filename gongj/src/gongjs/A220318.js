/**
 * 
 */
 //클래스 기본
  class Ramen{
	call(name){
		this.name="name";
	}
	//라면쪽 이걸해도 되고1
	hot(taste){ 
		this.taste=taste;
	}
	static Saythis(){ // 메소드에 static를 붙일시 정적메소드가 된다.
		alert(`${this.name}은  ${this.taste} 맛이다.`);
	}
}

//라면쪽 이걸해도 되고2
/*Ramen.prototype.taste = function() { 
  this.taste=taste;
};*/

/*let Ram = new Ramen();
Ram.name = "열라면";
Ram.taste="매운";
Ram.Saythis();
//==============
//[]로 이름만들기

/*class User {

  ['Ra' + 'men']() {
    alert("신라면");
  }

}

new User().Ramen();*/
//===============
//상속 (기본꺼 이어서함.)
/*class cool extends Ramen{
	no_hot(){
		alert(this.name + "은" + this.taste + "것이기에 안매운게 좋다." );
	}
}

let nRam = new cool("진라면");
nRam.name = "열라면";
nRam.taste="매운";
//alert(nRam instanceof Ramen); // 상속받는지 확인하는것.
nRam.no_hot();*/




