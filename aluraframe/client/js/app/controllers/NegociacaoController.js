// aluraframe/client/js/app/controllers/NegociacaoController.js

class NegociacaoController {

    constructor() {

        let $ = document.querySelector.bind(document);
        this._inputData = $('#data');
        this._inputQuantidade = $('#quantidade');
        this._inputValor = $('#valor');
        this._listaNegociacoes = new ListaNegociacoes(); // Nova Lista de Negociação

        this._negociacoesView = new NegociacoesView($('#negociacoesView'));
        this._negociacoesView.update(this._listaNegociacoes);

        this._mensagemView = new MensagemView($('#mensagemView'));
        this._mensagem = new Mensagem();
    }

    adiciona(event) {

        event.preventDefault();


        this._listaNegociacoes.adiciona(this._criaNegociacao());
        this._negociacoesView.update(this._listaNegociacoes);
        this._mensagem.texto = 'Negociação Adicionada com Sucesso !';
        this._mensagemView.update(this._mensagem);
        this._limpa();

    }

    _criaNegociacao() {
        return new Negociacao(
            DateHelper.textoData(this._inputData.value),
            this._inputQuantidade.value,
            this._inputValor.value
        );
    }

    _limpa() {

        this._inputQuantidade.value = 1;
        this._inputValor.value = 0, 0;
        this._inputData.value = '';
        this._inputData.focus();
    }


}