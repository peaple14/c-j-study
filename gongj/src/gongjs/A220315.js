/**
 * 
 */
 function clickk(){
	alert(`OK`);
}


let animal = {
  eats: true,
  run() {
    alert("동물이 뜁니다.");
  }
};

let rabbit = {
  jumps: true,
  __proto__: animal //읽기만가능,수정은불가능
};
/*rabbit.__proto__=animal;*/ //이렇게 해도 됨.

rabbit.run();


