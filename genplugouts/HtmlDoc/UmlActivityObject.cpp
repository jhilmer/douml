
#include "UmlActivityDiagram.h"
#include "UmlActivityObject.h"
//Added by qt3to4:
#include <QByteArray>

QByteArray UmlActivityObject::sKind()
{
    return "activity object";
}

void UmlActivityObject::html(QByteArray pfix, unsigned int rank, unsigned int level)
{
    define();

    fw.write("<table><tr><td><div class=\"element\">Activity object <b>");
    writeq(name());
    fw.write("</b></div></td></tr></table>\n");

    html_internal(pfix, rank, level);

    unload(FALSE, FALSE);
}

void UmlActivityObject::html_internal(QByteArray pfix, unsigned int rank, unsigned int level)
{
    QByteArray s = description();

    s = description();

    if (!s.isEmpty()) {
        fw.write("<p>");
        writeq(s);
        fw.write("<br /></p>");
    }

    fw.write("<p>Type : ");
    write(type(), cppLanguage);
    fw.write("</p>");

    if (! multiplicity().isEmpty()) {
        fw.write("<p>Multiplicity : ");
        writeq(multiplicity());
        fw.write("</p>");
    }

    if (! inState().isEmpty()) {
        fw.write("<p>In State : ");
        writeq(inState());
        fw.write("</p>");
    }

    s = selection();

    QByteArray scpp = cppSelection();
    QByteArray sjava = javaSelection();

    if (!s.isEmpty() || !scpp.isEmpty() || !sjava.isEmpty()) {
        fw.write("<p>Selection :</p><ul>");

        if (!s.isEmpty()) {
            fw.write("<li>OCL : <pre>\n");
            writeq(s);
            fw.write("</pre></li>");
        }

        if (!scpp.isEmpty()) {
            fw.write("<li>C++ : <pre>\n");
            writeq(scpp);
            fw.write("</pre></li>");
        }

        if (!sjava.isEmpty()) {
            fw.write("<li>Java : <pre>\n");
            writeq(sjava);
            fw.write("</pre></li>");
        }

        fw.write("</ul>");
    }

    if (ordering() != unordered) {
        fw.write("<p>Ordering : ");
        write(ordering());
        fw.write("</p>");
    }

    if (isControlType())
        fw.write("<p>Is control type</p>\n");

    UmlActivityDiagram * d = associatedDiagram();

    if (d != 0) {
        fw.write("<p>Diagram : ");
        d->write();
        fw.write("</p>");
    }

    write_properties();

    write_children(pfix, rank, level);

}

