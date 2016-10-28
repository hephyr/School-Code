var Animal = {
  createNew: function() {
    var animal = {};
    animal.n = '';
    animal.c = '';
    animal.character = [];
    animal.hasCharacter = function(chars) {
      for (var i = 0; i < chars.length; ++i) {
        cha = chars[i];
        if (animal.character.indexOf(cha) == -1) {
          return false;
        }
      }
      return true;
    };
    return animal;
  }
};

var Mammal = {
  createNew: function() {
    var mammal = Animal.createNew();
    mammal.c = "哺乳动物";
    mammal.character.push(mammal.c);
    mammal.character.push("哺乳");
    mammal.character.push("产仔");
    for (var i = 0; i < arguments.length; i++) {
      if (i === 0) {
        mammal.n = arguments[0];
      } else {
        mammal.character.push(arguments[i]);
      }
    }
    return mammal;
  }
};

var Bird = {
  createNew: function() {
    var bird = Animal.createNew();
    bird.c = "鸟类";
    bird.character.push(bird.c);
    bird.character.push("会下蛋");
    bird.character.push("有翅膀");
    bird.character.push("有羽毛");
    for (var i = 0; i < arguments.length; i++) {
      if (i === 0) {
        bird.n = arguments[0];
      } else {
        bird.character.push(arguments[i]);
      }
    }
    return bird;
  }
};

var animals = [];
var cat = Mammal.createNew("猫", "有毛", "爱吃鱼");
var dog = Mammal.createNew("狗", "有毛", "爱吃肉");
var bird = Bird.createNew("鸵鸟", "不会飞", "跑得快");

animals.push(cat);
animals.push(dog);
animals.push(bird);


function submitForm() {
  var cha = document.getElementById("example").value;
  var arr_cha = cha.split(" ");
  if (cha.length === 0) {
    alert("请输入");
  } else {
    var results = coreFun(arr_cha);
    showResutlt("pic", results);
  }
}

function coreFun(chars) {
  var results = [];
  for (var i = 0; i < animals.length; ++i) {
    var a = animals[i];
    if (a.hasCharacter(chars)) {
      results.push(a.n);
    }
  }
  return results;
}

function showResutlt(pic_id, results) {
  var pic = document.getElementById(pic_id);
  var p = document.createElement("h3");
  p.id = 'ch';
  var text;
  if (results.length !== 0) {
    text = document.createTextNode(results);
  } else {
    text = document.createTextNode("未检索到");
  }
  if (document.getElementById('ch')) {
    var term = document.getElementById('ch');
    pic.removeChild(term);
  }
  p.appendChild(text);
  pic.appendChild(p);
}
