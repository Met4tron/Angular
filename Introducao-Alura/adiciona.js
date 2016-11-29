let botao1 = document.querySelector('#adicionar-paciente');

botao1.addEventListener("click",function(event){
  event.preventDefault(); // Impede comportamento Padrão

  var campoNome = document.querySelector('#campo-nome');
  var campoPeso = document.querySelector('#campo-peso');
  var campoAltura = document.querySelector('#campo-altura');



  var pacienteNovo = "<tr class = 'paciente'>" +
      "<td class='info-nome'>"+ campoNome.value +"</td>" +
      "<td class='info-peso'>"+ campoPeso.value +"</td>" +
      "<td class='info-altura'>"+ campoAltura.value +"</td>" +
      "<td class='info-imc'>"+ campoPeso.value / (campoAltura.value * campoAltura.value) +"</td>" +
      "</tr>";
var tabela = document.querySelector('table');
tabela.innerHTML = tabela.innerHTML + pacienteNovo;

campoNome.value="";
campoAltura.value="";
campoPeso.value="";
});
