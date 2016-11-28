// aluraframe/client/js/app/controllers/NegociacaoController.js

class NegociacaoController {

    constructor() {

        let $ = document.querySelector.bind(document);
        this._inputData = $('#data');
        this._inputQuantidade = $('#quantidade');
        this._inputValor = $('#valor');
    }

    adiciona(event) {

        event.preventDefault();

        let negociacao = new Negociacao(
            DateHelper.textoData(this._inputData.value),
            this._inputQuantidade.value,
            this._inputValor.value
        );

        console.log(negociacao);
       /* this._inputQuantidade.value = 1;
        this._inputValor.value = 0.0;
        this._inputData.focus();
       */

      let dataCerta = DateHelper.dataTexto(negociacao.data);

       console.log(dataCerta);
    }

    
}