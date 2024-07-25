import pytest
from io import StringIO
from Source.Agenda import Agenda

def test_mostrar_sem_evento(capsys):
    agenda = Agenda()
    agenda.get_Eventos()
    out, _ = capsys.readouterr()
    assert out.strip() == 'Nenhum evento agendado.'

def test_mostrar_um_evento(capsys):
    agenda = Agenda()
    agenda.add_Eventos()
    agenda.get_Eventos()
    out, _ = capsys.readouterr()
    assert out.strip() == 'Final dos 100m: 2024-07-24 10:00 a 2024-07-24 11:00'