//calcula-imc.js

let botao = document.querySelector('#calcula-imcs');
botao.addEventListener("click", () => {

    let trsPacientes = document.querySelectorAll("paciente");

    precorreArray(trsPacientes, (pacienteTr) => {

        let tdNome = pacienteTr.querySelectorAll(".info-nome")[0];
        let tdPeso = pacienteTr.querySelectorAll(".info-peso")[0];
        let tdAltura = pacienteTr.querySelectorAll(".info-altura")[0];

        let pacienteAtual = {
            nome: tdNome.textContent,
            peso: tdPeso.textContent,
            altura: tdAltura.textContent,
            pegaImc: () => {

                if (this.altura != 0) {
                    let imc = this.peso / (this.altura * this.altura);
                    return imc;
                } else {

                    console("Não posso dividir por zero!");
                }
            }
        };

        let imc = pacienteAtual.pegaImc();

        let tdImc = pacienteTr.querySelectorAll("info-imc")[0];
        tdImc.textContent = imc;

        console.log(imc);
    });
});
