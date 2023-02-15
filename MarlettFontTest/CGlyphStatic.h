#pragma once


// CGlyphStatic

class CGlyphStatic : public CStatic
{
	DECLARE_DYNAMIC(CGlyphStatic)

protected:
    WORD glyph_id_ = 0;

public:
	CGlyphStatic();
	virtual ~CGlyphStatic();

    WORD GetGlyph() const noexcept { return this->glyph_id_; }
    void SetGlyph(WORD glyph_id);

protected:
	DECLARE_MESSAGE_MAP()
public:
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
    virtual void PreSubclassWindow();
};


